#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (auto& v : x) cin >> v;

    vector<ll> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    vector<ll> inv(n);
    inv[n - 1] = 1;
    for (int i = n - 1; i > 0; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }

    vector<ll> prob(n);
    for (int i = 0; i < n; i++) {
        prob[i] = inv[n - i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll p = prob[i];
        ans = (ans + p * (x[i + 1] - x[i]) % MOD * fac[n - 2]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}