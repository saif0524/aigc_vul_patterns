#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll n, t;
vector<vector<int>> adj;
vector<int> dp, fac, ifac;

ll powmod(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

ll choose(ll n, ll k) {
    if (k > n) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void dfs(int u, int p) {
    if (adj[u].size() == 1 && u != 1) {
        dp[u] = 1;
        return;
    }
    ll total = 0, ways = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        total += dp[v];
        ways = 1LL * ways * (1 + dp[v]) % MOD;
    }
    dp[u] = total + 1;
    t = 1LL * t * ways % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(n+1, 0);
    t = 1;
    fac.resize(n+1, 1);
    ifac.resize(n+1, 1);
    for(int i=2;i<=n;i++){
        fac[i] = 1LL * fac[i-1] * i % MOD;
        ifac[i] = powmod(fac[i], MOD - 2);
    }
    dfs(1, -1);
    ll res = 0;
    for(int i=0;i<n;i++){
        ll ways = 1;
        ll sum = 0;
        for(int v : adj[1]){
            if(dp[v] >= i){
                ways = 1LL * ways * choose(dp[v], i) % MOD;
                sum += dp[v];
            }
        }
        res = (res + 1LL * ways * powmod(2, n - 2 - sum + i) % MOD) % MOD;
    }
    cout << 1LL * res * t % MOD;
    return 0;
}