#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[p[i]]++;
    }

    int ans = 1;
    for (auto& it : cnt) {
        ans = (1LL * ans * (it.second + 1)) % MOD;
    }

    int half = (ans + 1) / 2;
    int res = 0;
    for (int mask = 0; mask < (1 << cnt.size()); mask++) {
        int prod = 1;
        int cnt_primes = 0;
        int i = 0;
        for (auto& it : cnt) {
            if (mask & (1 << i)) {
                prod = (1LL * prod * it.second) % MOD;
                cnt_primes++;
            }
            i++;
        }
        if (cnt_primes % 2 == 1) {
            res = (res + prod) % MOD;
        } else {
            res = (res + MOD - prod) % MOD;
        }
    }

    cout << (half + res) % MOD << endl;

    return 0;
}