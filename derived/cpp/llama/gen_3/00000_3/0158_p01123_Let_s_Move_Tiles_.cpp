#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

vector<vector<char>> board;
int n;
string seq;

void applyMove(char move) {
    if (move == 'U') {
        for (int j = 0; j < n; ++j) {
            vector<char> column;
            for (int i = 0; i < n; ++i) {
                if (board[i][j] != '.') {
                    column.push_back(board[i][j]);
                }
            }
            int index = 0;
            for (int i = 0; i < n; ++i) {
                if (index < column.size()) {
                    board[i][j] = column[index];
                    ++index;
                } else {
                    board[i][j] = '.';
                }
            }
        }
    } else if (move == 'D') {
        for (int j = 0; j < n; ++j) {
            vector<char> column;
            for (int i = 0; i < n; ++i) {
                if (board[i][j] != '.') {
                    column.push_back(board[i][j]);
                }
            }
            int index = column.size() - 1;
            for (int i = n - 1; i >= 0; --i) {
                if (index >= 0) {
                    board[i][j] = column[index];
                    --index;
                } else {
                    board[i][j] = '.';
                }
            }
        }
    } else if (move == 'L') {
        for (int i = 0; i < n; ++i) {
            vector<char> row;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    row.push_back(board[i][j]);
                }
            }
            int index = 0;
            for (int j = 0; j < n; ++j) {
                if (index < row.size()) {
                    board[i][j] = row[index];
                    ++index;
                } else {
                    board[i][j] = '.';
                }
            }
        }
    } else if (move == 'R') {
        for (int i = 0; i < n; ++i) {
            vector<char> row;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    row.push_back(board[i][j]);
                }
            }
            int index = row.size() - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (index >= 0) {
                    board[i][j] = row[index];
                    --index;
                } else {
                    board[i][j] = '.';
                }
            }
        }
    }
}

void parseSequence(int& pos) {
    while (pos < seq.size()) {
        if (seq[pos] == '(') {
            ++pos;
            vector<char> subSeq;
            int count = 0;
            while (seq[pos] != ')') {
                if (isdigit(seq[pos])) {
                    count = count * 10 + (seq[pos] - '0');
                    ++pos;
                } else {
                    subSeq.push_back(seq[pos]);
                    ++pos;
                }
            }
            ++pos;
            if (count == 0) {
                count = 1;
            }
            for (int i = 0; i < count; ++i) {
                for (char c : subSeq) {
                    applyMove(c);
                }
            }
        } else {
            applyMove(seq[pos]);
            ++pos;
        }
    }
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        board.assign(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        cin >> seq;
        parseSequence(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}