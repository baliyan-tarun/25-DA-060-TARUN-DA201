#include <iostream>
#include <vector>
using namespace std;

int n;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve(vector<vector<int>>& board, int col) {
    if (col >= n)
        return true;

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solve(board, col + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}