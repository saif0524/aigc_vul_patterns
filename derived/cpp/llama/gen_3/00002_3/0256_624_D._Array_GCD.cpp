#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1000001;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    ll ans = 1e18;

    for (int d = -1; d <= 1; ++d) {
        for (int p = 2; p <= 100; ++p) {
            ll cur = 0;
            int i, j;
            for (i = 0; i < n && v[i] % p > d; ++i) cur += b;
            for (j = n - 1; j >= 0 && v[j] % p > d; --j) cur += b;

            for (int k = 0; k < n; ++k) {
                ll tmp = cur;
                if (v[k] % p > d) tmp -= b;
                for (int l = k; l < n; ++l) {
                    if (v[l] % p > d) tmp -= b;
                    ans = min(ans, tmp + a * (l - k + 1));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}