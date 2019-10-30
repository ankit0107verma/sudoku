//17571@nith.ac.in (mail address) @Ankit Verma
#include<bits/stdc++.h>
using namespace std;
const int D = 9;
// function for printing board
void printBoard(int board[D][D], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << setw(3) << board[i][j] << " ";
       }
       cout << endl;
	}
}
//function to check whether currNum can be placed at a given position
bool canPlace(int board[D][D], int n, int row, int col, int curNum) {
	if(board[row][col] != 0) return false; // if it was fixed cell
	// check the row and column 
	for(int x = 0; x < n; x++) {
		if(board[row][x] == curNum) return false; // row already contains that number
         if(board[x][col] == curNum) return false; // col has that number
    }
    int rootn = sqrt(n);
    int boxRow = row/rootn;
    int boxCol = col/rootn; // coordinates of bigger box
    int boxStartCellRow = boxRow * rootn;
    int boxStartCellCol = boxCol * rootn;
    for(int i = boxStartCellRow; i < boxStartCellRow + rootn; i++) {
    	for(int j = boxStartCellCol; j < boxStartCellCol + rootn; j++) {
    		if(board[i][j] == curNum) return false;
    	}
    }
       return true;

}
bool solveSudoku(int board[D][D], int n, int row, int col) {
    if(row == n) {
    	// this means I have solved the entire board
    	return true;
    }
    if(col == n) {
    	// if column reaches end go to next row and make col zero
    	return solveSudoku(board, n, row+1, 0);
    }

    if(board[row][col] != 0) return solveSudoku(board, n, row, col + 1); // move the the next col
	for(int curNum = 1; curNum <= n; curNum++) {
		if(canPlace(board, n, row, col, curNum) == true) {
			board[row][col] = curNum;
			bool success = solveSudoku(board, n, row, col+1);
			if(success) return true;
		   // bactrack
				board[row][col] = 0; 
		}
	}
	return false;
}
void inputMat(int mat[][9], int m, int n) {
    cout << "\n-----Enter MAT----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}
int main()
{
  int board[D][D] = {0};
  cout << "Enter size of the board " << endl;
  int n; cin >> n; // n should be pefect square
  inputMat(board, n, n);
  bool success = solveSudoku(board, n, 0, 0);
  if(success){
  	printBoard(board, n);
  }
  else {
  	cout << "I can't solve neither you can" << endl;
  }
  return 0;
}
