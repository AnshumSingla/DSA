#include <iostream>
#include <vector>
using namespace std;

bool isSafe2(vector<vector<int>>& board, int row, int col, int N) {
  // Check row on left side
  for (int j = 0; j < col; j++)
    if (board[row][j])
      return false;

  // Using sum of coordinates for one diagonal
  int sum = row + col;
  for (int i = 0; i < N; i++) {
    int j = sum - i;
    if (j >= 0 && j < N && board[i][j])
      return false;
  }

  // Using difference of coordinates for other diagonal
  int diff = row - col;
  for (int i = 0; i < N; i++) {
    int j = i - diff;
    if (j >= 0 && j < N && board[i][j])
      return false;
  }

  return true;
}

bool solveNQueenUtil(vector<vector<int>>& board, int col, int N) {
  if (col >= N)
    return true;

  for (int i = 0; i < N; i++) {
    if (isSafe2(board, i, col, N)) {
      board[i][col] = 1;

      if (solveNQueenUtil(board, col + 1, N))
        return true;

      board[i][col] = 0;
    }
  }
  return false;
}

void printSolution(vector<vector<int>>& board, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int N;
  cout << "Enter the size of board: ";
  cin >> N;

  vector<vector<int>> board(N, vector<int>(N, 0));

  if (!solveNQueenUtil(board, 0, N)) {
    cout << "Solution does not exist" << endl;
    return 0;
  }

  printSolution(board, N);
  return 0;
}