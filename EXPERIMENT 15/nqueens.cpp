//Navya Gupta 25/DA/047
#include <iostream>
#include <vector>
using namespace std;

int n;

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "NAVYA GUPTA ROLL NO 25/DA/047" << endl;
    cout << "N-Queens Problem using Backtracking" << endl;

    cout << "Enter the value of N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid value of N" << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}