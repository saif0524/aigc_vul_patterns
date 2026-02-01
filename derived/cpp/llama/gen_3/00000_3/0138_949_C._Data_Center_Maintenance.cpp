#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

vector<int> g[MAX_N];
int u[MAX_N], v[MAX_N], color[MAX_N];
bool used[MAX_N];

void dfs(int x, int c) {
    used[x] = true;
    color[x] = c;
    for (int i = 0; i < g[x].size(); i++) {
        int to = g[x][i];
        if (!used[to]) {
            dfs(to, 1 - c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h;
    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> u[i];
    }

    for (int i = 1; i <= m; i++) {
        if ((u[i] + 1) % h == (u[v[i]] + 1) % h) {
            g[v[i]].push_back(i + n);
            g[i + n].push_back(v[i]);
        }
        if ((v[i] + 1) % h == (u[i] + 1) % h) {
            g[i].push_back(i + n);
            g[i + n].push_back(i);
        }
    }

    for (int i = 1; i <= n + m; i++) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            ans++;
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            cout << i << " ";
        }
    }

    return 0;
}