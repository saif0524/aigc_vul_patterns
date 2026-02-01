#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> b(n), a(n);
    for(auto &x: b) cin >> x;
    for(auto &x: a) cin >> x;
    vector<vector<pair<int, ll>>> g(n);
    for(int i=1;i<n;i++){
        int x;
        ll k;
        cin >> x >> k;
        x--;
        g[x].push_back({i, k});
        g[i].push_back({x, 1});
    }
    vector<ll> total(n, 0);
    function<void(int, int)> dfs = [&](int u, int p){
        total[u] = b[u] - a[u];
        for(auto [v, k]: g[u]){
            if(v == p) continue;
            dfs(v, u);
            total[u] += (total[v] + k-1) / k;
        }
    };
    dfs(0, -1);
    cout << (total[0] >= 0 ? "YES" : "NO");
}