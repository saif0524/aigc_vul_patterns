#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    ll n;
    cin >> n;
    ll max_lcm = 1;
    if (n >= 2) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-1, n-2)));
    }
    if (n >= 3) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-1, n-3)));
    }
    if (n >= 4) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-1, n-4)));
        max_lcm = max(max_lcm, lcm(n, lcm(n-2, n-3)));
    }
    if (n >= 5) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-2, n-4)));
        max_lcm = max(max_lcm, lcm(n, lcm(n-3, n-4)));
    }
    if (n >= 6) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-3, n-5)));
        max_lcm = max(max_lcm, lcm(n-2, lcm(n-3, n-4)));
    }
    if (n >= 7) {
        max_lcm = max(max_lcm, lcm(n, lcm(n-4, n-5)));
        max_lcm = max(max_lcm, lcm(n-1, lcm(n-3, n-5)));
    }
    cout << max_lcm;
}