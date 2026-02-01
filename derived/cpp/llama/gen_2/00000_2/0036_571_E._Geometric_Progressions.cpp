#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll lcm_val = b[0];
    for (int i = 1; i < n; i++) {
        lcm_val = lcm(lcm_val, b[i]);
    }

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (lcm_val == b[i]) {
                ans = 1;
                break;
            }
            continue;
        }
        ll val = lcm_val / b[i];
        if (val == 0) {
            continue;
        }
        ll temp = a[i];
        while (temp % a[i]) {
            temp *= b[i];
            if (temp > 1e18) break;
        }
        if (temp % a[i] == 0 && temp % lcm_val == 0) {
            if (ans == -1) {
                ans = temp;
            } else {
                ans = gcd(ans, temp);
            }
        } else {
            ans = -1;
            break;
        }
    }

    if (ans == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans % mod << '\n';
    }
}