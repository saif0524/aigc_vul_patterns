#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 105;
const int MAXK = 105;

int N, M, K;
ll D;
ll fact[MAXK], inv_fact[MAXK];

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % D * inv_fact[n - r] % D;
}

ll calculate() {
    ll ans = 0;
    vector<vector<ll>> dp(N + M, vector<ll>(K + 1, 0));
    for (int i = 0; i <= K; ++i) dp[0][i] = 1;

    for (int i = 1; i < N + M; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % D;
        }
    }

    ll total_ways = modpow(K, N * M, D);
    for (int sum = 0; sum <= K * (N + M - 1); ++sum) {
        ll contribution = 0;
        for (int r = 0; r <= min(sum, N * (K - 1)); ++r) {
            ll c = sum - r;
            ll ways_to_choose_r = nCr(N * (K - 1), r);
            ll ways_to_choose_c = nCr(M * (K - 1), c);
            if (ways_to_choose_r == 0 || ways_to_choose_c == 0) continue;
            contribution = (contribution + (ways_to_choose_r * ways_to_choose_c % D * dp[N + M - 2][sum] % D)) % D;
        }
        ans = (ans + contribution * modpow(K, N * M - sum, D)) % D;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K >> D;
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i <= K; i++){
        fact[i] = fact[i - 1] * i % D;
        inv_fact[i] = modpow(fact[i], D - 2, D);
    }
    cout << calculate() << "\n";
}