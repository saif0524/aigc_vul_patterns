#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> c(n), t(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<ll> diff(1, 0);
    for (ll i = 0; i < n; i++) {
        diff.push_back(c[i] - t[i]);
    }
    for (ll i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
    }

    bool flag = true;
    for (ll i = 1; i <= n - 1; i++) {
        if (diff[i] != 0) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}