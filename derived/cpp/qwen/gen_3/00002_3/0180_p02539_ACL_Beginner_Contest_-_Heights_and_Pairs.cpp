#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> heights(2 * N);
    for (int &h : heights) cin >> h;
    
    sort(heights.begin(), heights.end());
    long long ans = 1;
    for (int i = 0; i < 2 * N; i += 2) {
        if (heights[i] == heights[i + 1]) {
            cout << 0;
            return 0;
        }
        ans = (ans * (i + 1)) % MOD;
    }
    long long inv_fact = modpow(2, N, MOD);
    inv_fact = modpow(inv_fact, MOD - 2, MOD);
    ans = (ans * inv_fact) % MOD;
    cout << ans;
}