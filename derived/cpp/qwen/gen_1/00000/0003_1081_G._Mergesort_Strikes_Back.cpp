#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MOD = 998244353;

ll fastPow(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = fastPow(x, y / 2, m) % m;
    p = (p * p) % m;
    return y % 2 ? (p * x) % m : p;
}

ll modInv(ll a, ll p) {
    return fastPow(a, p - 2, p);
}

ll nCr(ll n, ll r, ll p) {
    if (r > n) return 0;
    ll num = 1, den = 1;
    for (ll i = 1; i <= r; ++i) {
        num = (num * (n - r + i)) % p;
        den = (den * i) % p;
    }
    return (num * modInv(den, p)) % p;
}

ll compute(ll n, ll k, ll q) {
    if (n == 1) return 0;
    ll mid = (n + 1) / 2;
    ll totalInversions = 0;
    for (ll i = 0; i <= k; ++i) {
        ll leftInversions = compute(mid, k - i, q);
        ll rightInversions = compute(n - mid, i, q);
        ll mergeInversions = (mid * (n - mid)) % q;
        ll ways = nCr(k, i, q);
        totalInversions = (totalInversions + ((ways * (leftInversions + rightInversions + mergeInversions)) % q)) % q;
    }
    return totalInversions;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, q;
    cin >> n >> k >> q;
    ll totalPermutations = fastPow(2, k, q);
    ll totalInversions = compute(n, k, q);
    ll invTotalPermutations = modInv(totalPermutations, q);
    ll result = (totalInversions * invTotalPermutations) % q;
    cout << result;
}