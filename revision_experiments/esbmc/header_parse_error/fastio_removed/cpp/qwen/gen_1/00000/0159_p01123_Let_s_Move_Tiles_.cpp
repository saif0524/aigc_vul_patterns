// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

vector<vector<char>> board;
int n;

void moveUp() {
    for (int c = 0; c < n; ++c) {
        int pos = 0;
        for (int r = 0; r < n; ++r) {
            if (board[r][c] != '.') {
                if (board[pos][c] == '.') {
                    board[pos][c] = board[r][c];
                    board[r][c] = '.';
                } else {
                    if (++pos != r) {
                        board[pos][c] = board[r][c];
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
}

void moveDown() {
    for (int c = 0; c < n; ++c) {
        int pos = n - 1;
        for (int r = n - 1; r >= 0; --r) {
            if (board[r][c] != '.') {
                if (board[pos][c] == '.') {
                    board[pos][c] = board[r][c];
                    board[r][c] = '.';
                } else {
                    if (--pos != r) {
                        board[pos][c] = board[r][c];
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
}

void moveLeft() {
    for (int r = 0; r < n; ++r) {
        int pos = 0;
        for (int c = 0; c < n; ++c) {
            if (board[r][c] != '.') {
                if (board[r][pos] == '.') {
                    board[r][pos] = board[r][c];
                    board[r][c] = '.';
                } else {
                    if (++pos != c) {
                        board[r][pos] = board[r][c];
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
}

void moveRight() {
    for (int r = 0; r < n; ++r) {
        int pos = n - 1;
        for (int c = n - 1; c >= 0; --c) {
            if (board[r][c] != '.') {
                if (board[r][pos] == '.') {
                    board[r][pos] = board[r][c];
                    board[r][c] = '.';
                } else {
                    if (--pos != c) {
                        board[r][pos] = board[r][c];
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
}

void executeMove(char move) {
    switch (move) {
        case 'U': moveUp(); break;
        case 'D': moveDown(); break;
        case 'L': moveLeft(); break;
        case 'R': moveRight(); break;
    }
}

void parseAndExecuteSequence(string& seq, int repeat) {
    for (int i = 0; i < repeat; ++i) {
        for (char c : seq) {
            if (c == '(') {
                int openCount = 0;
                size_t start = i + 1;
                while (openCount != 0 || c != ')') {
                    if (c == '(') ++openCount;
                    if (c == ')') --openCount;
                    ++i;
                    c = seq[i];
                }
                size_t multiStart = i + 1;
                while (isdigit(seq[multiStart])) ++multiStart;
                long long multiplier = stoll(seq.substr(i + 1, multiStart - i - 1));
                parseAndExecuteSequence(seq.substr(start, i - start), multiplier);
                i = multiStart - 1;
            } else {
                executeMove(c);
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    while (cin >> n && n != 0) {
        board.assign(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        string seq;
        cin >> seq;
        parseAndExecuteSequence(seq, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
}