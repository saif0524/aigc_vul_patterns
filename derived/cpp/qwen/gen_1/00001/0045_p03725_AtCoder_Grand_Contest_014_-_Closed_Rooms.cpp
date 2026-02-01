#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A(H);
    for (auto &a : A) cin >> a;

    int si = -1, sj = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 'S') {
                si = i;
                sj = j;
                break;
            }
        }
    }

    auto in_bounds = [&](int i, int j) {
        return 0 <= i && i < H && 0 <= j && j < W;
    };

    auto is_locked = [&](int i, int j) {
        return A[i][j] == '#';
    };

    auto is_exit = [&](int i, int j) {
        return i == 0 || i == H - 1 || j == 0 || j == W - 1;
    };

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    deque<tuple<int, int, int, int, vector<vector<bool>>>> q;
    q.emplace_back(si, sj, 0, 0, vector<vector<bool>>(H, vector<bool>(W)));

    vector<vector<bool>> visited(H, vector<bool>(W));
    visited[si][sj] = true;

    int result = -1;

    while (!q.empty()) {
        auto [i, j, moves, unlocks, grid] = q.front();
        q.pop_front();

        if (is_exit(i, j)) {
            result = unlocks;
            break;
        }

        if (moves < K) {
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (in_bounds(ni, nj) && !grid[ni][nj] && !visited[ni][nj]) {
                    if (is_locked(ni, nj)) {
                        q.emplace_back(ni, nj, 0, unlocks + 1, grid);
                        visited[ni][nj] = true;
                    } else {
                        vector<vector<bool>> ngrid = grid;
                        ngrid[ni][nj] = true;
                        q.emplace_back(ni, nj, moves + 1, unlocks, ngrid);
                    }
                }
            }
        }

        if (unlocks < K) {
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (in_bounds(ni, nj) && is_locked(ni, nj) && !grid[ni][nj] && !visited[ni][nj]) {
                    vector<vector<bool>> ngrid = grid;
                    ngrid[ni][nj] = true;
                    q.emplace_back(ni, nj, 0, unlocks + 1, ngrid);
                    visited[ni][nj] = true;
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}