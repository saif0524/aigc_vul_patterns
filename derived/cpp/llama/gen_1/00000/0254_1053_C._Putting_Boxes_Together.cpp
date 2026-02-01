#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), w(n);
    for (auto& x : a) cin >> x;
    for (auto& x : w) cin >> x;

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            w[-x - 1] = y;
        } else {
            ll sum = 0;
            ll cnt = 0;
            ll avg = 0;
            for (int i = x - 1; i < y; i++) {
                sum += w[i];
                cnt++;
            }
            avg = sum / cnt;
            ll ans = 0;
            for (int i = x - 1; i < y; i++) {
                ll dist = abs(a[i] - (a[x - 1] + i - x + 1));
                ans += (dist * w[i]) % MOD;
                ans %= MOD;
            }
            for (int i = x - 1; i < y; i++) {
                ll dist = abs(a[i] - (a[y - 1] - y + i + 1));
                ll tmp = (dist * w[i]) % MOD;
                ans = min(ans, (ans + tmp - (ans % MOD)) % MOD);
                ans %= MOD;
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}