#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 505;
const int INF = 1e9;

struct Node {
    int x, y, len;
};

int n, m, g[MAX_N][MAX_N], dis[MAX_N][MAX_N], dx[MAX_N], dy[MAX_N], vis[MAX_N][MAX_N];
vector<int> pathx, pathy;

void printPath() {
    cout << dis[n][1] << endl;
    for (int i = 0; i <= dis[n][1]; i++) {
        cout << dx[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= dis[n][1]; i++) {
        cout << dy[i] << " ";
    }
    cout << endl;
}

void BFS() {
    queue<Node> q;
    Node start = {1, n, 0};
    q.push(start);
    dis[1][n] = 0;
    dx[0] = 1;
    dy[0] = n;
    vis[1][n] = 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (g[now.x][i] && !vis[i][now.y]) {
                vis[i][now.y] = 1;
                Node nxt = {i, now.y, now.len + 1};
                dis[i][now.y] = now.len + 1;
                dx[now.len + 1] = i;
                dy[now.len + 1] = now.y;
                q.push(nxt);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (g[now.y][i] && !vis[now.x][i]) {
                vis[now.x][i] = 1;
                Node nxt = {now.x, i, now.len + 1};
                dis[now.x][i] = now.len + 1;
                dx[now.len + 1] = now.x;
                dy[now.len + 1] = i;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    BFS();
    if (dis[n][1] == 0) {
        cout << -1 << endl;
    } else {
        printPath();
    }
    return 0;
}