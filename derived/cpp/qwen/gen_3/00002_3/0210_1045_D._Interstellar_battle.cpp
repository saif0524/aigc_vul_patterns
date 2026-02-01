#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
double prob[MAXN];
vector<int> G[MAXN];
double dp[MAXN][2];

void dfs(int u, int p) {
    dp[u][0] = 1.0 - prob[u];
    dp[u][1] = prob[u];
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] *= (dp[v][0] + dp[v][1]);
        dp[u][1] *= dp[v][1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> prob[i];
    for(int i=0;i<N-1;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    int Q;
    cin >> Q;
    while(Q--){
        int node;
        double new_prob;
        cin >> node >> new_prob;
        double old_dp0 = dp[node][0];
        double old_dp1 = dp[node][1];
        dp[node][0] = 1.0 - new_prob;
        dp[node][1] = new_prob;
        for(int v : G[node]){
            dp[v][0] *= (old_dp0 + old_dp1) / (dp[v][0] + dp[v][1]);
            dp[v][1] *= old_dp1 / dp[v][1];
            dfs(v, node);
        }
        double expected_kingdoms = dp[0][0];
        for(int v : G[0]){
            expected_kingdoms += dp[v][0] + dp[v][1];
        }
        cout << fixed << setprecision(5) << expected_kingdoms << "\n";
    }
}