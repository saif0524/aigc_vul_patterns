#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, dist[N][N], depth[N];
bool vis[N];

void query(int u) {
    cout << "? " << u << endl;
    for (int i = 1; i <= n; i++) {
        cin >> dist[u][i];
    }
}

void dfs(int u, int fa, int dep) {
    vis[u] = true;
    depth[u] = dep;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && dist[u][v] == dep + 1) {
            dfs(v, u, dep + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        query(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!dist[i][j]) {
                dist[i][j] = dist[j][i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, 0);
        }
    }

    cout << "!" << endl;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if ((abs(depth[i] - depth[j]) == 1) && dist[i][j] == abs(depth[i] - depth[j])) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}