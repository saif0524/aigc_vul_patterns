#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int N;
vector<vector<int>> G;
vector<int> sz;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    G.resize(N);
    sz.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1);

    int ans = 1;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j : G[i]) {
            if (sz[j] * 2 > N) continue;
            cnt++;
        }
        if (cnt > 0) {
            ans = (1LL * ans * cnt) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}