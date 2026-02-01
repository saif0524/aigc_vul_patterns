#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

int n, k;
vector<int> adj[MAXN];
int depth[MAXN];
int cnt_leaf[MAXN];
int ans;

void dfs(int v, int p) {
    if (adj[v].empty()) {
        depth[v] = 0;
        cnt_leaf[v] = 1;
    } else {
        depth[v] = -1;
        cnt_leaf[v] = 0;
        for (auto u : adj[v]) {
            if (u == p) continue;
            dfs(u, v);
            depth[v] = max(depth[v], depth[u] + 1);
            cnt_leaf[v] += cnt_leaf[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, 1);

    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) {
            int cur = i;
            int c = 0;
            while (c < k && cur != 1) {
                cur = adj[cur][0];
                c++;
            }
            ans = max(ans, cnt_leaf[cur]);
        }
    }

    cout << ans << endl;

    return 0;
}