#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 810;
const int MAXK = 810 * 810;

struct Node {
    int x, y, k, step;
};

int h, w, k;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXK];

int main() {
    cin >> h >> w >> k;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    queue<Node> q;
    int sx, sy;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    q.push({sx, sy, k, 0});
    vis[sx][sy][k] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Node u = q.front();
        q.pop();

        if (u.x == 1 || u.x == h || u.y == 1 || u.y == w) {
            cout << u.step << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];

            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w &&!vis[nx][ny][u.k]) {
                if (a[nx][ny] == '.') {
                    vis[nx][ny][u.k] = true;
                    q.push({nx, ny, u.k, u.step});
                } else if (u.k > 0) {
                    vis[nx][ny][u.k - 1] = true;
                    q.push({nx, ny, u.k - 1, u.step});
                }
            }
        }

        if (u.k > 0) {
            for (int i = 0; i < 4; i++) {
                int nx = u.x + dx[i];
                int ny = u.y + dy[i];

                if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && a[nx][ny] == '#' &&!vis[nx][ny][u.k - 1]) {
                    vis[nx][ny][u.k - 1] = true;
                    q.push({nx, ny, u.k - 1, u.step + 1});
                }
            }
        }
    }

    return 0;
}