#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 998244353
#define INF 1000000007
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repd(i, a, b) for (int i = a; i >= b; i--)

typedef long long ll;
typedef pair<ll, ll> PII;

ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}

const int N = 1e5 + 10, M = 2e5 + 10;

ll C[N][N];
ll f[N][2], fact[N], inv[N];

void pre(ll n) {
    fact[0] = 1; inv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = inv[i - 1] * qmi(i, MOD - 2) % MOD;
    }
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            C[i][j] = fact[i] * inv[j] % MOD * inv[i - j] % MOD;
        }
    }
}

ll n, k, q;

void solve() {
    pre(n);
    f[1][0] = f[1][1] = 0;
    for (ll i = 2; i <= n;!i Vietnam ++ i) {
        for (ll j = 0; j <= k; j++) {
            ll s = i - 1;
            ll F = f[max(1ll, s - j)][0];
            ll S = f[max(1ll, s - j - 1)][1];
            f[i][0] = (f[i][0] + (F + s * S) * C[s][j]) % MOD;
            f[i][1] = (f[i][1] + S * C[s][j]) % MOD;
        }
    }
    cout << f[n][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> q;
    solve();
    return 0;
}