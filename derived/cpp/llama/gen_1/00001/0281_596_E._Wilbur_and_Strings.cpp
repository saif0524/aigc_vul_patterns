#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m, q;
vector<string> table;
vector<pair<int, int>> moves;
bool visited[200][200];
bool can_reach[200][200][10];

void bfs(int x, int y, int d) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    can_reach[x][y][d] = true;

    while (!q.empty()) {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        int next_x = curr_x + moves[d].first;
        int next_y = curr_y + moves[d].second;

        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y]) {
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
            can_reach[next_x][next_y][table[next_x][next_y] - '0'] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    table.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    moves.resize(10);
    for (int i = 0; i < 10; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d = table[i][j] - '0';
            if (!can_reach[i][j][d]) {
                bfs(i, j, d);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        bool found = false;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                int idx = 0;
                while (idx < s.length()) {
                    if (can_reach[x][y][s[idx] - '0']) {
                        idx++;
                        int next_x = x + moves[s[idx - 1] - '0'].first;
                        int next_y = y + moves[s[idx - 1] - '0'].second;
                        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
                            break;
                        }
                        x = next_x;
                        y = next_y;
                    } else {
                        break;
                    }
                }
                if (idx == s.length()) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}