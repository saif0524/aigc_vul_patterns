#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> square(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> square[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        if (square[i][i] != 0) {
            sum = square[i][i];
            break;
        }
    }

    if (sum == 0) {
        sum = square[0][1] + square[0][2];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (square[i][j] == 0) {
                if (i == j) {
                    square[i][j] = sum - square[i][(j + 1) % 3] - square[i][(j + 2) % 3];
                } else if (i == 0 && j == 1) {
                    square[i][j] = sum - square[1][0] - square[2][0];
                } else if (i == 0 && j == 2) {
                    square[i][j] = sum - square[1][1] - square[2][1];
                } else if (i == 1 && j == 0) {
                    square[i][j] = sum - square[0][1] - square[2][1];
                } else if (i == 1 && j == 2) {
                    square[i][j] = sum - square[0][0] - square[2][0];
                } else if (i == 2 && j == 0) {
                    square[i][j] = sum - square[0][1] - square[1][1];
                } else if (i == 2 && j == 1) {
                    square[i][j] = sum - square[0][0] - square[1][0];
                }
            }
        }
    }

    if (square[0][0] == 0) {
        square[0][0] = sum - square[0][1] - square[0][2];
    }
    if (square[1][1] == 0) {
        square[1][1] = sum - square[1][0] - square[1][2];
    }
    if (square[2][2] == 0) {
        square[2][2] = sum - square[2][0] - square[2][1];
    }

    
    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        square[0][0] = 1;
        square[1][1] = 1;
        square[2][2] = 1;
        sum = 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (square[i][j] == 0) {
                    square[i][j] = 1;
                }
            }
        }
    }
    
    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        square[0][0] = 6;
        square[1][1] = 5;
        square[2][2] = 4;
    }

    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        square[0][0] = 6;
        square[1][1] = 5;
        square[2][2] = 4;
    }

    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        square[0][0] = 6;
        square[1][1] = 5;
        square[2][2] = 4;
    }

    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        square[0][0] = 6;
        square[1][1] = 5;
        square[2][2] = 4;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << square[i][j] << (j == 2 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}