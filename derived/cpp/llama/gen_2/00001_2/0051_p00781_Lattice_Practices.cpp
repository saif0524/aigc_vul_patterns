#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int rotation[] = {0, 1, 5, 6, 15, 14, 13, 12, 8, 9};
const int verticalMask = 0x1f;
const int horizontalMask = 0x7f80;

int calculate(const vector<int> &board) {
    vector<int> uniqueBoards;
    for (int i = 0; i < 10; i++) {
        bool found = false;
        for (auto &b : uniqueBoards) {
            if (b == board[i] || (b ^ board[i]) == 0x1f) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueBoards.push_back(board[i]);
        }
    }
    int count = 0;
    for (int v1 = 0; v1 < 10; v1++) {
        for (int v2 = v1 + 1; v2 < 10; v2++) {
            for (int v3 = v2 + 1; v3 < 10; v3++) {
                for (int v4 = v3 + 1; v4 < 10; v4++) {
                    for (int v5 = v4 + 1; v5 < 10; v5++) {
                        int v = board[v1] | (board[v2] << 5) | (board[v3] << 10) | (board[v4] << 15) | (board[v5] << 20);
                        if (!(v & verticalMask) && !(v & (verticalMask << 5)) && !(v & (verticalMask << 10)) && !(v & (verticalMask << 15)) && !(v & (verticalMask << 20))) {
                            for (int h1 = 0; h1 < 10; h1++) {
                                if (h1 == v1 || h1 == v2 || h1 == v3 || h1 == v4 || h1 == v5) {
                                    continue;
                                }
                                for (int h2 = h1 + 1; h2 < 10; h2++) {
                                    if (h2 == v1 || h2 == v2 || h2 == v3 || h2 == v4 || h2 == v5) {
                                        continue;
                                    }
                                    for (int h3 = h2 + 1; h3 < 10; h3++) {
                                        if (h3 == v1 || h3 == v2 || h3 == v3 || h3 == v4 || h3 == v5) {
                                            continue;
                                        }
                                        for (int h4 = h3 + 1; h4 < 10; h4++) {
                                            if (h4 == v1 || h4 == v2 || h4 == v3 || h4 == v4 || h4 == v5) {
                                                continue;
                                            }
                                            for (int h5 = h4 + 1; h5 < 10; h5++) {
                                                if (h5 == v1 || h5 == v2 || h5 == v3 || h5 == v4 || h5 == v5) {
                                                    continue;
                                                }
                                                int h = (board[h1] << 25) | (board[h2] << 30) | (board[h3] << 0) | (board[h4] << 5) | (board[h5] << 10);
                                                if (!(h & (horizontalMask << 0)) && !(h & (horizontalMask << 5)) && !(h & (horizontalMask << 10)) && !(h & (horizontalMask << 15)) && !(h & (horizontalMask << 20))) {
                                                    int mask = (1 << 25) | (1 << 20) | (1 << 15) | (1 << 10) | (1 << 5);
                                                    if (((v >> 20) & 0x1f) == ((h >> 25) & 0x1f) && ((v >> 15) & 0x1f) == ((h >> 20) & 0x1f) && ((v >> 10) & 0x1f) == ((h >> 15) & 0x1f) && ((v >> 5) & 0x1f) == ((h >> 10) & 0x1f) && ((v >> 0) & 0x1f) == ((h >> 5) & 0x1f)) {
                                                        count++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return count / 8;
}

int calculateRotated(const vector<int> &board) {
    vector<int> rotatedBoards;
    rotatedBoards.push_back(board[0]);
    for (int i = 1; i < 10; i++) {
        rotatedBoards.push_back(board[rotation[i]]);
    }
    return calculate(rotatedBoards);
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == "END") {
            break;
        }
        vector<int> board;
        size_t pos = 0;
        while ((pos = input.find(" ")) != string::npos) {
            string s = input.substr(0, pos);
            int x = 0;
            for (char c : s) {
                x = (x << 1) | (c == '0' ? 0 : 1);
            }
            board.push_back(x);
            input.erase(0, pos + 1);
        }
        int x = 0;
        for (char c : input) {
            x = (x << 1) | (c == '0' ? 0 : 1);
        }
        board.push_back(x);
        cout << calculate(board) << endl;
    }
    return 0;
}