#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkWin(const vector<string>& field, char player) {
    // Check rows
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (field[i][j] == player && field[i][j + 1] == player && field[i][j + 2] == player) {
                return true;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (field[i][j] == player && field[i + 1][j] == player && field[i + 2][j] == player) {
                return true;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (field[i][j] == player && field[i + 1][j + 1] == player && field[i + 2][j + 2] == player) {
                return true;
            }
            if (field[i][j + 2] == player && field[i + 1][j + 1] == player && field[i + 2][j] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<string> field(4);
    for (int i = 0; i < 4; i++) {
        cin >> field[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (field[i][j] == '.') {
                field[i][j] = 'x';
                if (checkWin(field, 'x')) {
                    cout << "YES" << endl;
                    return 0;
                }
                field[i][j] = '.';
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}