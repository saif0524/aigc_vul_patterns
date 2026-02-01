#include <iostream>
#include <vector>
using namespace std;

bool checkWin(char board[4][4]) {
    // check rows
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[i][j] == 'x' && board[i][j+1] == 'x' && board[i][j+2] == 'x') {
                return true;
            }
        }
    }

    // check columns
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 'x' && board[i+1][j] == 'x' && board[i+2][j] == 'x') {
                return true;
            }
        }
    }

    // check diagonals
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[i][j] == 'x' && board[i+1][j+1] == 'x' && board[i+2][j+2] == 'x') {
                return true;
            }
        }
    }

    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[i][j] == 'x' && board[i-1][j+1] == 'x' && board[i-2][j+2] == 'x') {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }

    bool win = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '.') {
                board[i][j] = 'x';
                win = checkWin(board);
                board[i][j] = '.';
                if (win) {
                    break;
                }
            }
        }
        if (win) {
            break;
        }
    }

    if (win) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}