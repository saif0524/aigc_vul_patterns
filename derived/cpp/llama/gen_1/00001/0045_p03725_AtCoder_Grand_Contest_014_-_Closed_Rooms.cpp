#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

int h, w, k;
vector<string> grid;
vector<vector<bool>> visited;

int bfs(int si, int sj) {
    queue<tuple<int, int, int, int>> q;
    q.push({si, sj, 0, k});
    visited[si][sj] = true;

    while (!q.empty()) {
        auto [i, j, dist, remaining] = q.front();
        q.pop();

        if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
            return dist;
        }

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (0 <= ni && ni < h && 0 <= nj && nj < w) {
                if (!visited[ni][nj] && grid[ni][nj] == '.') {
                    visited[ni][nj] = true;
                    q.push({ni, nj, dist, remaining});
                } else if (remaining > 0 && grid[ni][nj] == '#') {
                    visited[ni][nj] = true;
                    q.push({ni, nj, dist, remaining - 1});
                }
            }
        }

        if (remaining > 0) {
            q.push({i, j, dist + 1, k});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> k;

    grid.resize(h);
    for (auto& row : grid) {
        cin >> row;
    }

    int si, sj;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }

    visited.resize(h, vector<bool>(w, false));

    cout << bfs(si, sj) << '\n';

    return 0;
}