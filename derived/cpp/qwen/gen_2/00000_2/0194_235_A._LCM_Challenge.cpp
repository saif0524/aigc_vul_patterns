#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll n;
    cin >> n;
    ll max_lcm = 1;
    for (ll i = n; i >= max(n-2, 1); --i) {
        for (ll j = n; j >= max(n-2, 1); --j) {
            for (ll k = n; k >= max(n-2, 1); --k) {
                max_lcm = max(max_lcm, lcm(lcm(i, j), k));
            }
        }
    }
    cout << max_lcm;
}