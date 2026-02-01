#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define ll long long
#define MOD 998244353

ll fastpow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (a * fastpow(a, n - 1, mod)) % mod;
    ll temp = fastpow(a, n / 2, mod);
    return (temp * temp) % mod;
}

ll inv(ll a, ll mod) {
    return fastpow(a, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    ll sum = 0;
    for (int d = 1; d <= n; d++) {
        ll cur = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            bool ok = true;
            int bal = 0;
            int curd = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    if (s[i] == '?') {
                        bal++;
                        curd = max(curd, bal);
                    } else if (s[i] == '(') {
                        bal++;
                        curd = max(curd, bal);
                    } else {
                        bal--;
                        if (bal < 0) {
                            ok = false;
                        }
                    }
                } else {
                    if (s[i] == '?') {
                        bal--;
                        if (bal < 0) {
                            ok = false;
                        }
                    } else if (s[i] == '(') {
                        ok = false;
                    } else {
                        bal--;
                        if (bal < 0) {
                            ok = false;
                        }
                    }
                }
            }
            if (ok && curd == d) {
                cur++;
            }
        }

        sum += (cur * d) % MOD;
        sum %= MOD;
    }

    cout << sum << "\n";

    return 0;
}