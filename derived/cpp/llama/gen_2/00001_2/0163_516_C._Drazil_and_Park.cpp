#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back

ll modexp(ll x, ll n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return (modexp((x * x) % mod, (n / 2)) % mod);
    } else {
        return ((x * modexp((x * x) % mod, ((n - 1) / 2))) % mod);
    }
}

ll power(ll x, ll n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return (power((x * x), (n / 2)));
    else
        return (x * power((x * x), ((n - 1) / 2)));
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

ll divide(ll x, ll y) {
    return mul(x, modexp(y, mod - 2));
}

ll min(ll x, ll y) { return (x > y ? y : x); }
ll max(ll x, ll y) { return (x > y ? x : y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tt;
    ll n, m;
    cin >> n >> m;
    ll distance[n];
    for (ll i = 0; i < n; i++) {
        cin >> distance[i];
    }
    ll h[n];
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll sum[n + 1];
    sum[0] = 0;
    for (ll i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + distance[i - 1];
    }
    ll answer = 0;
    ll a, b;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        ll best = 0;
        ll best1 = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                ll d;
                if (i < a && j < a) {
                    d = sum[j] - sum[i];
                }
                else if (i > b && j > b) {
                    d = sum[j] - sum[i];
                }
                else if (i < a && j > b) {
                    d = sum[n] - (sum[j] - sum[i]);
                }
                else if (i > b && j < a) {
                    d = sum[n] - (sum[i] - sum[j]);
                }
                else {
                    d = -1;
                }
                if (d != -1) {
                    best = max(best, (h[i - 1] + h[j - 1]) * 2 + d);
                }
            }
        }
        cout << best << "\n";
    }
    return 0;
}