#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, -1));
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    vector<int> dp(1 << 6, 0);
    dp[0] = dp[1] = dp[3] = dp[7] = dp[15] = dp[31] = dp[63] = 1;
    for(int mask = 1; mask < (1 << (3 * n)); ++mask){
        int p = __builtin_popcount(mask);
        if(p % 3 != 0) continue;
        int id = p / 3;
        int i = id / n, j = id % n;
        int k = 0;
        while(k < n && ((mask >> (3 * k + 2)) & 1)) k++;
        if(k == n) continue;
        int curr_mask = 0;
        if(adj[i][j] != -1){
            curr_mask |= (adj[i][j] & 1) << 0;
            curr_mask |= (adj[i][j] & 1) << 1;
        }
        if(adj[i][k] != -1){
            curr_mask |= (adj[i][k] & 1) << 0;
            curr_mask |= (adj[i][k] & 1) << 2;
        }
        if(adj[j][k] != -1){
            curr_mask |= (adj[j][k] & 1) << 1;
            curr_mask |= (adj[j][k] & 1) << 2;
        }
        for(int submask = curr_mask; submask; submask = (submask-1) & curr_mask){
            if(__builtin_popcount(submask) != 2) continue;
            int ni = i, nj = j, nk = k;
            int nmask = mask - (1 << (3 * i + (submask & 1))) - (1 << (3 * j + ((submask >> 1) & 1))) - (1 << (3 * k + ((submask >> 2) & 1)));
            int nid = nmask / ((1 << 3) - 1);
            ni = nid / n, nj = nid % n;
            nk = 0;
            while(nk < n && ((nmask >> (3 * nk + 2)) & 1)) nk++;
            dp[mask] = (dp[mask] + dp[nmask]) % MOD;
        }
    }
    int ans = 0;
    for(int mask = 1; mask < (1 << (3 * n)); ++mask){
        int p = __builtin_popcount(mask);
        if(p % 3 == 0){
            ans = (ans + dp[mask]) % MOD;
        }
    }
    cout << ans;
}