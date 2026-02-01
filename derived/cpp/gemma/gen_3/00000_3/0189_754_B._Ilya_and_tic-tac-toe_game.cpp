#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> board(4);
    for (int i = 0; i < 4; ++i) {
        cin >> board[i];
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == '.') {
                board[i][j] = 'x';
                
                // Check rows
                for (int row = 0; row < 4; ++row) {
                    int count = 0;
                    for (int col = 0; col < 4; ++col) {
                        if (board[row][col] == 'x') {
                            count++;
                        } else {
                            count = 0;
                        }
                        if (count == 3) {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }

                // Check columns
                for (int col = 0; col < 4; ++col) {
                    int count = 0;
                    for (int row = 0; row < 4; ++row) {
                        if (board[row][col] == 'x') {
                            count++;
                        } else {
                            count = 0;
                        }
                        if (count == 3) {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }

                // Check diagonals (top-left to bottom-right)
                for (int row = 0; row < 4; ++row) {
                    for (int col = 0; col < 4; ++col) {
                        if (row + 3 < 4 && col + 3 < 4) {
                            int count = 0;
                            for (int i = 0; i < 4; ++i) {
                                if (board[row + i][col + i] == 'x') {
                                    count++;
                                } else {
                                    count = 0;
                                }
                                if (count == 3) {
                                    cout << "YES" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }

                // Check diagonals (top-right to bottom-left)
                for (int row = 0; row < 4; ++row) {
                    for (int col = 0; col < 4; ++col) {
                        if (row + 3 < 4 && col - 3 >= 0) {
                            int count = 0;
                            for (int i = 0; i < 4; ++i) {
                                if (board[row + i][col - i] == 'x') {
                                    count++;
                                } else {
                                    count = 0;
                                }
                                if (count == 3) {
                                    cout << "YES" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }

                board[i][j] = '.';
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}