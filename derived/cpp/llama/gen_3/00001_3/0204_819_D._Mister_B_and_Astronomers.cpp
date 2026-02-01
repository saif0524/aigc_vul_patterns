#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    ll T, n;
    cin >> T >> n;

    vector<ll> a(n);
    for (ll& x : a) {
        cin >> x;
    }

    vector<ll> sum(n);
    partial_sum(a.begin(), a.end(), sum.begin());
    ll sum_all = sum.back();

    vector<ll> ans(n, 0);
    for (ll t = 0; t < T; ++t) {
        ll min_time = 1e18;
        ll min_id = -1;
        for (ll i = 0; i < n; ++i) {
            ll time = (t - (sum[i] % T) + T) % T;
            if (time < min_time) {
                min_time = time;
                min_id = i;
            }
        }
        ans[min_id]++;
    }

    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}