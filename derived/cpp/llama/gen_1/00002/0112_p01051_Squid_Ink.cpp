#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 100;
const int MAXM = 100;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct State {
    int x, y, d;
    State(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {}
};

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    int sx, sy, gx, gy;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    bool visited[R][C][4];
    memset(visited, false, sizeof(visited));
    queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push(State(sx, sy, i));
        visited[sx][sy][i] = true;
    }
    int dist[R][C][4];
    memset(dist, 0x3f, sizeof(dist));
    dist[sx][sy][0] = dist[sx][sy][1] = dist[sx][sy][2] = dist[sx][sy][3] = 0;
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int d = cur.d;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || grid[nx][ny] == '#' || grid[nx][ny] == 'x') {
                continue;
            }
            int nd = (grid[nx][ny] == 'o' || grid[nx][ny] == 'S' || grid[nx][ny] == 'G') ? 1 : 2;
            if (!visited[nx][ny][i]) {
                visited[nx][ny][i] = true;
                dist[nx][ny][i] = dist[x][y][d] + nd;
                q.push(State(nx, ny, i));
            } else if (dist[x][y][d] + nd < dist[nx][ny][i]) {
                dist[nx][ny][i] = dist[x][y][d] + nd;
                q.push(State(nx, ny, i));
            }
        }
        if (x == gx && y == gy) {
            int ans = INT_MAX;
            for (int i = 0; i < 4; i++) {
                ans = min(ans, dist[x][y][i]);
            }
            cout << ans << endl;
            return 0;
        }
        for (int i = 1; i <= 3; i++) {
            int nx = x + dir[d][0] * i;
            int ny = y + dir[d][1] * i;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || grid[nx][ny] == '#') {
                break;
            }
            if (!visited[nx][ny][d]) {
                visited[nx][ny][d] = true;
                dist[nx][ny][d] = dist[x][y][d] + 2;
                q.push(State(nx, ny, d));
            } else if (dist[x][y][d] + 2 < dist[nx][ny][d]) {
                dist[nx][ny][d] = dist[x][y][d] + 2;
                q.push(State(nx, ny, d));
            }
        }
    }
    return 0;
}