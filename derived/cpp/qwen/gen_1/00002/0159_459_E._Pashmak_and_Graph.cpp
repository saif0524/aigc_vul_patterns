#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int W = 1e5 + 5;

vector<pair<int, int>> g[N];
int dp[W];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(auto& [v, w] : g[i]){
            dp[w] = max(dp[w], dp[w-1] + 1);
            ans = max(ans, dp[w]);
        }
    }
    cout << ans;
}