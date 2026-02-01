#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MOD = 998244353;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> H(2 * N);
    map<int, int> cnt;
    for (int i = 0; i < 2 * N; i++) {
        cin >> H[i];
        cnt[H[i]]++;
    }

    long long ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = ans * i % MOD;
    }

    for (auto& it : cnt) {
        long long inv = modpow(it.second, MOD - 2);
        for (int i = 0; i < it.second - 1; i++) {
            ans = ans * (it.second - i) % MOD;
            ans = ans * inv % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}