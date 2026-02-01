#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll powerMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ll N;
    cin >> N;
    ll count = 0;
    for (ll i = 0; (1LL << i) <= 2 * N; ++i) {
        count = (count + powerMod(3, i, MOD)) % MOD;
    }
    cout << count << endl;
    return 0;
}