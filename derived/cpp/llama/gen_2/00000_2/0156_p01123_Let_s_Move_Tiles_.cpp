#include <bits/stdc++.h>
using namespace std;

const int N = 55;
char board[N][N];

void moveDown(int n) {
    for (int j = 0; j < n; j++) {
        vector<char> v;
        for (int i = 0; i < n; i++) {
            if (board[i][j] != '.') {
                v.push_back(board[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (!v.empty()) {
                board[i][j] = v.back();
                v.pop_back();
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void moveUp(int n) {
    for (int j = 0; j < n; j++) {
        vector<char> v;
        for (int i = 0; i < n; i++) {
            if (board[i][j] != '.') {
                v.push_back(board[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!v.empty()) {
                board[i][j] = v.back();
                v.pop_back();
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void moveLeft(int n) {
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                v.push_back(board[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            if (!v.empty()) {
                board[i][j] = v.back();
                v.pop_back();
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void moveRight(int n) {
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                v.push_back(board[i][j]);
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (!v.empty()) {
                board[i][j] = v.back();
                v.pop_back();
            } else {
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                board[i][j] = s[j];
            }
        }
        string seq;
        cin >> seq;
        int idx = 0;
        while (idx < seq.size()) {
            if (seq[idx] == '(') {
                int nest = 1;
                int end_idx = idx + 1;
                while (nest > 0) {
                    if (seq[end_idx] == '(') {
                        nest++;
                    } else if (seq[end_idx] == ')') {
                        nest--;
                    }
                    end_idx++;
                }
                int rep = 0;
                while (seq[end_idx] >= '0' && seq[end_idx] <= '9') {
                    rep = rep * 10 + seq[end_idx] - '0';
                    end_idx++;
                }
                string sub_seq = seq.substr(idx + 1, end_idx - idx - 2);
                for (int i = 0; i < rep; i++) {
                    for (char c : sub_seq) {
                        if (c == 'U') {
                            moveUp(n);
                        } else if (c == 'D') {
                            moveDown(n);
                        } else if (c == 'L') {
                            moveLeft(n);
                        } else if (c == 'R') {
                            moveRight(n);
                        }
                    }
                }
                idx = end_idx;
            } else {
                if (seq[idx] == 'U') {
                    moveUp(n);
                } else if (seq[idx] == 'D') {
                    moveDown(n);
                } else if (seq[idx] == 'L') {
                    moveLeft(n);
                } else if (seq[idx] == 'R') {
                    moveRight(n);
                }
                idx++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}