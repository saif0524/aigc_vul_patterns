#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll modpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    ll l = 1, r = 2e9;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        ll num_not_divisible_by_x = mid - mid / x;
        ll num_not_divisible_by_y = mid - mid / y;
        ll num_not_divisible_by_both = mid - mid / lcm(x, y);
        if (num_not_divisible_by_x >= cnt1 && num_not_divisible_by_both + cnt1 <= mid && num_not_divisible_by_y - (mid - num_not_divisible_by_both - cnt1) >= cnt2)
            r = mid;
        else
            l = mid;
    }
    cout << r;
    return 0;
}