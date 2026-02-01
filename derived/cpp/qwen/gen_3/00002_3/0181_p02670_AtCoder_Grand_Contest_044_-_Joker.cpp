#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N * N);
    for (int i = 0; i < N * N; ++i) {
        cin >> P[i];
    }
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = (i * N) + j + 1;
        }
    }
    vector<pair<int, int>> positions(N * N + 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            positions[grid[i][j]] = {i, j};
        }
    }
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int ans = 0;
    for (int p : P) {
        auto [x, y] = positions[p];
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            while (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                ans++;
                nx += dir[0];
                ny += dir[1];
            }
        }
        visited[x][y] = true;
    }
    cout << ans;
}