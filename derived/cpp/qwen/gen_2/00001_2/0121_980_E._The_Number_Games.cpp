#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sz(n+1, 0);
    vector<long long> fans(n+1, 0);
    function<void(int, int)> dfs = [&](int u, int p){
        sz[u] = 1;
        fans[u] = (1LL << u);
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            fans[u] += fans[v];
        }
    };
    dfs(1, -1);
    vector<pair<long long, int>> candidate;
    for(int i=2;i<=n;i++){
        candidate.emplace_back(fans[i], i);
    }
    sort(candidate.begin(), candidate.end());
    for(int i=0;i<k;i++){
        cout << candidate[i].second << (i < k-1 ? ' ' : '\n');
    }
}