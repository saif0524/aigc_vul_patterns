#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].pb(u);
        in[u]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans(n);
    int ptr = 1;
    while (!q.empty()) {
        queue<int> tmp;
        vector<int> v;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            v.pb(node);
        }
        sort(v.begin(), v.end());
        for (int node : v) {
            ans[node] = ptr++;
            for (int child : g[node]) {
                in[child]--;
                if (in[child] == 0) {
                    tmp.push(child);
                }
            }
        }
        q = tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}