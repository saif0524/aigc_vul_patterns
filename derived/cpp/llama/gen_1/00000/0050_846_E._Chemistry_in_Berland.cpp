#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> b(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, ll>> t(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> t[i].first >> t[i].second;
        t[i].first--;
    }

    for (int i = n - 2; i >= 0; i--) {
        int x = t[i].first;
        ll k = t[i].second;
        ll g = gcd(k, b[i + 1]);
        ll nb = b[x] * k + b[i + 1];
        b[x] = nb / g;
        b[i + 1] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] < a[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}