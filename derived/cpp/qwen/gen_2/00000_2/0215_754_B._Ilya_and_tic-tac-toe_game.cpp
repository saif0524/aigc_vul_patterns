#include <bits/stdc++.h>
using namespace std;

bool check(vector<string>& board, int x, int y) {
    board[x][y] = 'x';
    // Check row
    for (int i = 0; i < 4; ++i) {
        if (board[x][i] != 'x') break;
        if (i == 3) return true;
    }
    // Check column
    for (int i = 0; i < 4; ++i) {
        if (board[i][y] != 'x') break;
        if (i == 3) return true;
    }
    // Check main diagonal
    if (x == y) {
        for (int i = 0; i < 4; ++i) {
            if (board[i][i] != 'x') break;
            if (i == 3) return true;
        }
    }
    // Check anti-diagonal
    if (x + y == 3) {
        for (int i = 0; i < 4; ++i) {
            if (board[i][3-i] != 'x') break;
            if (i == 3) return true;
        }
    }
    board[x][y] = '.';
    return false;
}

int main() {
    vector<string> board(4);
    for (int i = 0; i < 4; ++i) cin >> board[i];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == '.') {
                if (check(board, i, j)) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}