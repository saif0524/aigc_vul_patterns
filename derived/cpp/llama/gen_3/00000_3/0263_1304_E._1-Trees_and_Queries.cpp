#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pi pair<int, int>
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define mod 1000000007

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
int n, q, dist[100005][100005];

void dfs(int node, int parent, int x, vector<vector<int>>& adj, vector<int>& dist) {
    for (auto child : adj[node]) {
        if (child != parent) {
            dist[child] = dist[node] + 1;
            dfs(child, node, x, adj, dist);
        }
    }
}

void solve() {
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        vector<int> dist1(n + 1, 0), dist2(n + 1, 0);
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        dfs(x, 0, x, adj, dist1);
        dfs(y, 0, y, adj, dist2);
        if (k >= dist1[a] + dist2[b] - dist1[y] - dist2[x] && k <= dist1[a] + dist2[b] - dist1[y] - dist2[x] + 2 * (min(dist1[x], dist2[x]) + min(dist1[y], dist2[y]) - 1)) {
            if (k % 2 == (dist1[a] + dist2[b] - dist1[y] - dist2[x]) % 2 || k == dist1[a] + dist2[b] - dist1[y] - dist2[x] + 2 * (min(dist1[x], dist2[x]) + min(dist1[y], dist2[y]) - 1)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}