#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long long MOD = 998244353;

long long modPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

long long modInv(long long a) {
    return modPow(a, MOD - 2);
}

long long fact[100005], invFact[100005];

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[100000] = modInv(fact[100000]);
    for (int i = 100000 - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

long long comb(int n, int k) {
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int N;
    cin >> N;

    vector<int> h(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> h[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < 2 * N; i++) {
        cnt[h[i]]++;
    }

    long long ans = fact[N];
    for (auto& p : cnt) {
        ans = ans * invFact[p.second / 2] % MOD;
    }

    for (auto& p : cnt) {
        if (p.second % 2 == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 0; i < 2 * N; i++) {
        ans = ans * (N - (cnt[h[i]] / 2 - 1)) % MOD;
        cnt[h[i]]--;
    }

    cout << ans << endl;

    return 0;
}