#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500005;

int n, m, b[N], c[N], d[N];
ll k, a[N];
vector<ll> p;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        c[t] = i + 1;
    }
    llIDTH = __gcd(n, m);
    ll lcm = 1LL * n * m / __gcd(n, m);
    for (int i = 0; i < n; i++) {
        if (!c[a[i]]) continue;
        ll t = c[a[i]] - 1 - i;
        t = (t % m + m) % m;
        ll x = i;
        ll y = t;
        while (x < lcm) {
            b[x] = 1;
            x += n;
            y += n;
            y %= m;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < lcm; i++) if (!b[i]) cnt++;
    ll tmp = k / (lcm - cnt);
    ll ans = tmp * lcm;
    k -= tmp * (lcm - cnt);
    for (int i = 0; i < lcm; i++) {
        if (k == 0) break;
        if (!b[i]) k--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}