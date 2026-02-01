#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXD = 15;

ll dp[MAXN][MAXD];
ll sum[MAXD];
ll mod;

void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAXD; j++) {
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < MAXD; j++) {
            sum[j] = (sum[j - 1] + dp[i][j]) % mod;
        }
    }
}

ll pow_mod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

ll C(int n, int m) {
    if (n < m) return 0;
    ll res = 1;
    for (int i = 1; i <= m; i++) {
        res = (res * (n - i + 1)) % mod;
        res = (res * pow_mod(i, mod - 2)) % mod;
    }
    return res;
}

int main() {
    int n, d;
    cin >> n >> d >> mod;
    init(n);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            if (i - 1 < j) continue;
            for (int k = 1; k <= j; k++) {
                ll ways = C(j, k);
                ll rem = i - k - 1;
                if (rem < 0) continue;
                ways = (ways * sum[k]) % mod;
                ll trees = dp[rem][d - k];
                if (rem == 0 && d - k > 1) trees = 0;
                if (rem == 0 && d - k == 1) trees = 1;
                dp[i][j] = (dp[i][j] + (ways * trees) % mod) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= d; i++) {
        if ((n - 1) % i == 0 && (d - i) <= 1) {
            ans = (ans + dp[n - 1][i]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}