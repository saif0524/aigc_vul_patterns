#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 505;
const int MAX_M = 10005;

struct Edge {
    int to, next;
};

Edge edges[MAX_M * 2];
int head[MAX_N], cnt;

void addEdge(int u, int v) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

int n, m;
int dis[MAX_N][MAX_N];
int pre[MAX_N][MAX_N];

void bfs(int s, int t) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = -1;
        }
    }
    dis[s][t] = 0;
    q.push(s);
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        for (int i = head[u]; i!= -1; i = edges[i].next) {
            int to = edges[i].to;
            if (dis[to][v] == -1) {
                dis[to][v] = dis[u][v] + 1;
                pre[to][v] = u;
                q.push(to);
                q.push(v);
            }
        }
        for (int i = head[v]; i!= -1; i = edges[i].next) {
            int to = edges[i].to;
            if (dis[u][to] == -1) {
                dis[u][to] = dis[u][v] + 1;
                pre[u][to] = v;
                q.push(u);
                q.push(to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    bfs(1, n);
    if (dis[n][1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << dis[n][1] << endl;
    vector<int> path1, path2;
    int u = n, v = 1;
    while (u!= 1 || v!= n) {
        path1.push_back(u);
        path2.push_back(v);
        int temp = u;
        u = pre[u][v];
        v = pre[temp][v];
    }
    path1.push_back(1);
    path2.push_back(n);
    for (int i = 0; i < path1.size(); i++) {
        cout << path1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < path2.size(); i++) {
        cout << path2[i] << " ";
    }
    cout << endl;
    return 0;
}