#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXQ = 1000005;
const int DIRS = 10;

int n, m, q;
char grid[MAXN][MAXN];
int dx[DIRS], dy[DIRS];
string queries[MAXQ];
bool visited[MAXN][MAXN][DIRS];
bool canReach[MAXN][MAXN][DIRS][MAXQ];

bool bfs(int startX, int startY, int index) {
    queue<tuple<int, int, int>> q;
    q.push({startX, startY, grid[startX][startY] - '0'});
    visited[startX][startY][grid[startX][startY] - '0'] = true;
    canReach[startX][startY][grid[startX][startY] - '0'][index] = true;

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        int nextX = x + dx[d];
        int nextY = y + dy[d];

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
            int nextDigit = grid[nextX][nextY] - '0';
            if (!visited[nextX][nextY][nextDigit]) {
                visited[nextX][nextY][nextDigit] = true;
                canReach[nextX][nextY][nextDigit][index] = true;
                q.push({nextX, nextY, nextDigit});
            }
        }
    }
    return canReach[startX][startY][grid[startX][startY] - '0'][index];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < DIRS; i++) {
        cin >> dx[i] >> dy[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    for (int index = 0; index < q; index++) {
        const string& query = queries[index];
        memset(visited, false, sizeof(visited));
        memset(canReach, false, sizeof(canReach));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bfs(i, j, index);
            }
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int digit = grid[i][j] - '0';
                int k = 0;
                int x = i;
                int y = j;
                while (k < query.size()) {
                    int targetDigit = query[k] - '0';
                    if (!canReach[x][y][digit][index]) break;
                    x += dx[digit];
                    y += dy[digit];
                    if (x < 0 || x >= n || y < 0 || y >= m) break;
                    digit = grid[x][y] - '0';
                    k++;
                }
                if (k == query.size()) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}