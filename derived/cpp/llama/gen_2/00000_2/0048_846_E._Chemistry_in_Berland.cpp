#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<pair<int, ll>> x(n);
    for (int i = 1; i < n; ++i) {
        int p;
        ll k;
        cin >> p >> k;
        --p;
        x[i] = {p, k};
    }

    for (int i = n - 1; i > 0; --i) {
        int p = x[i].first;
        ll k = x[i].second;
        ll g = gcd(k, a[i]);
        a[p] += a[i] / g * k;
        b[p] += b[i] / g * k;
        a[i] = a[i] % g;
        b[i] = b[i] % g;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (a[i] > b[i])
            ok = false;

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    solve();
    return 0;
}