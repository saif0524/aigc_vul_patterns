#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

struct State {
    int r, c, inkdir;
    int time;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    int Sr = -1, Sc = -1, Gr = -1, Gc = -1;
    for (int r = 0; r < R; ++r) {
        cin >> grid[r];
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 'S') {
                Sr = r;
                Sc = c;
            } else if (grid[r][c] == 'G') {
                Gr = r;
                Gc = c;
            }
        }
    }

    vector<vector<vector<bool>>> vis(R, vector<vector<bool>>(C, vector<bool>(4)));
    queue<State> q;
    q.push({Sr, Sc, -1, 0});
    vis[Sr][Sc][-1 + 4] = true;

    while (!q.empty()) {
        auto [r, c, inkdir, time] = q.front(); q.pop();

        if (r == Gr && c == Gc) {
            cout << time << "\n";
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') continue;

            int cost = 1;
            if (grid[nr][nc] == 'o' || (inkdir != -1 && inkdir == dir)) cost = 1; // same condition

            if (!vis[nr][nc][dir + 4]) {
                q.push({nr, nc, inkdir, time + cost});
                vis[nr][nc][dir + 4] = true;
            }
        }

        if (inkdir == -1) {
            for (int dir = 0; dir < 4; ++dir) {
                bool possible = true;
                vector<bool> can_ink(R, vector<bool>(C));
                can_ink[r][c] = true;
                for (int dist = 1; dist <= 3; ++dist) {
                    int nr = r + dist * dr[dir];
                    int nc = c + dist * dc[dir];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) break;
                    if (grid[nr][nc] == '#') break;
                    can_ink[nr][nc] = true;
                }

                if (vis[r][c][dir + 4]) continue;
                q.push({r, c, dir, time + 2});
                vis[r][c][dir + 4] = true;
            }
        }
    }

    return 0;
}