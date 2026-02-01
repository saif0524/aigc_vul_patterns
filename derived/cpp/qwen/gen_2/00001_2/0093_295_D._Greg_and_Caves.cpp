#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll dp[2001][2001], f[2001][2001], inv[2001], f_inv[2001];

ll power(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    f[0] = f_inv[0] = inv[1] = dp[0][0] = 1;
    for(int i = 1; i <= m; ++i){
        inv[i] = power(i, MOD-2);
        f[i] = f[i-1] * i % MOD;
        f_inv[i] = f_inv[i-1] * inv[i] % MOD;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 2; j <= m; ++j){
            for(int k = 1; k <= j-1; ++k){
                int left = f[j-2] * f_inv[k-1] % MOD * f_inv[j-1-k] % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][k] * left % MOD) % MOD;
            }
        }
        for(int j = 1; j <= m; ++j){
            f[j] = (f[j] + dp[i][j]) % MOD;
        }
    }

    cout << f[m] << "\n";
}