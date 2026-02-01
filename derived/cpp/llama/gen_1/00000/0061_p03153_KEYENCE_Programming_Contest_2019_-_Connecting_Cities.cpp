#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll d;
    cin >> n >> d;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += d * (i + 1);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    ans += sum;

    ll x = a[0] + a[n - 1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll tmp = a[i] + a[j] + d * abs(i - j);
            if (tmp < x) {
                x = tmp;
            }
        }
    }

    ans += x;

    cout << ans << endl;

    return 0;
}