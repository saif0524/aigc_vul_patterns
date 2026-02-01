#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

ll maxLCM(ll n) {
    ll maxlcm = 1;
    for (ll i = n; i >= max(1LL, n - 2); --i) {
        for (ll j = n; j >= max(1LL, n - 2); --j) {
            for (ll k = n; k >= max(1LL, n - 2); --k) {
                maxlcm = max(maxlcm, lcm(lcm(i, j), k));
            }
        }
    }
    return maxlcm;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << maxLCM(n) << "\n";
    return 0;
}