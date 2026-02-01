#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1005;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node {
    int x, y, step, apples;
    Node(int x = 0, int y = 0, int step = 0, int apples = 0) : x(x), y(y), step(step), apples(apples) {}
};

char grid[MAXN][MAXN];
int h, w, k, sx, sy, ex, ey;
bool visited[MAXN][MAXN][21];

void bfs() {
    queue<Node> q;
    q.push(Node(sx, sy, 0, 0));
    visited[sx][sy][0] = true;

    while (!q.empty()) {
        Node u = q.front();
        q.pop();

        if (u.x == ex && u.y == ey && u.apples >= k) {
            cout << u.step << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = u.x + dir[i][0];
            int ny = u.y + dir[i][1];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] == '#') {
                continue;
            }

            int na = u.apples + (grid[nx][ny] == 'a');
            if (!visited[nx][ny][na]) {
                visited[nx][ny][na] = true;
                q.push(Node(nx, ny, u.step + 1, na));
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin >> h >> w >> k;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'e') {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    return 0;
}