#include <bits/stdc++.h>

using namespace std;

const int SIZE = 4;

bool is_valid_move(int x, int y) {
    return x >= 0 && x < SIZE - 1 && y >= 0 && y < SIZE - 1;
}

bool is_valid_position(int x, int y, const vector<vector<bool>>& state) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (state[x + i][y + j]) {
                return false;
            }
        }
    }
    return true;
}

bool next_position(int& x, int& y, const vector<vector<int>>& days, int day, int& week) {
    if (week == 6) {
        for (int i = 0; i < SIZE - 1; ++i) {
            for (int j = 0; j < SIZE - 1; ++j) {
                if (!is_valid_position(i, j, days[day])) {
                    for (int dx = -2; dx <= 2; ++dx) {
                        for (int dy = -2; dy <= 2; ++dy) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (abs(dx) + abs(dy) <= 2 && is_valid_move(nx, ny) && is_valid_position(nx, ny, days[day])) {
                                x = nx;
                                y = ny;
                                week = 0;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (abs(dx) + abs(dy) <= 1 && is_valid_move(x + dx, y + dy)) {
                x += dx;
                y += dy;
                week = 0;
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> days;
    int N;
    while (cin >> N) {
        if (N == 0) break;
        days.resize(N + 1);
        for (int i = 0; i < N; ++i) {
            days[i + 1].resize(SIZE * SIZE);
            for (int j = 0; j < SIZE * SIZE; ++j) {
                cin >> days[i + 1][j];
            }
        }
        vector<vector<bool>> state(SIZE, vector<bool>(SIZE, false));
        for (int i = 2; i < 4; ++i) {
            for (int j = 2; j < 4; ++j) {
                state[i][j] = true;
            }
        }
        days[0] = vector<int>(SIZE * SIZE, 0);
        for (int i = 2; i < 4; ++i) {
            for (int j = 2; j < 4; ++j) {
                days[0][i * SIZE + j] = 1;
            }
        }
        int x = 2;
        int y = 2;
        bool is_possible = true;
        for (int i = 0; i <= N; ++i) {
            if (!is_valid_position(x, y, days[i])) {
                int week = 0;
                for (int j = i - 1; j >= 0; --j) {
                    is_valid_position(x, y, days[j]) ? week = 0 : ++week;
                    if (week == 7) {
                        is_possible = false;
                        break;
                    }
                }
            }
            if (!is_possible) break;
            if (i < N) {
                is_possible = next_position(x, y, days, i, 0);
            }
        }
        cout << (is_possible ? 1 : 0) << endl;
    }
    return 0;
}