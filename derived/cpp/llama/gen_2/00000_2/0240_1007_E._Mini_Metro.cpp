#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ll n, t, k;
    cin >> n >> t >> k;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<ll> people(n);
    for (int i = 0; i < n; i++) {
        people[i] = a[i];
    }

    ll ans = 0;

    for (int hour = 0; hour < t; hour++) {
        ll total = 0;
        ll need = 0;
        for (int i = 0; i < n; i++) {
            if (people[i] > c[i]) {
                need = LLONG_MAX;
                break;
            }
            need += max(0LL, c[i] - people[i]);
            total += b[i];
        }

        if (need > 0) {
            ans += (need + k - 1) / k;
            for (int i = 0; i < n; i++) {
                people[i] = min(c[i], people[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            people[i] += b[i];
        }
    }

    cout << ans << endl;
    return 0;
}