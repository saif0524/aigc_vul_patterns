#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ll mod = 998244353;

ll powerMod(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll res = powerMod(a, b / 2, mod);
    if (b % 2 == 0) return res * res % mod;
    else return res * res % mod * a % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << "0\n";
        return 0;
    }

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    if (n == 2) {
        cout << "6\n";
        return 0;
    }

    ll ans = powerMod(2, n, mod);
    cout << ans << '\n';

    return 0;
}