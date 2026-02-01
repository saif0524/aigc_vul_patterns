#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

ll n, k;
vector<ll> adj[MAXN];
ll dp[MAXN][2];

void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 0;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dp[v][0] > dp[v][1]) {
            dp[u][1] += dp[v][0];
        } else {
            dp[u][1] += dp[v][1];
            dp[u][0] += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(n, 0);

    vector<int> ans;
    if (dp[n][1] < dp[n][0]) {
        ans.push_back(n);
    }

    vector<int> order;
    for (int i = 1; i <= n; ++i) {
        order.push_back(i);
    }

    sort(order.begin(), order.end(), [](int u, int v) {
        return adj[u].size() > adj[v].size();
    });

    for (int i : order) {
        if ((int)ans.size() == k) break;
        if (adj[i].size() == 1 && i != n) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}