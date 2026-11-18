#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp &1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M, K;
    cin >> N >> M >> K;
    
    long long total_cards = N + M + K;
    long long total_patterns = modpow(3LL, total_cards, MOD);
    
    long long alice_wins = 0;
    
    for (long long i = 0; i <= N; ++i) {
        for (long long j = 0; j <= M; ++j) {
            long long remaining = total_cards - i - j;
            if (remaining < K) continue;
            
            long long ways_to_choose = modpow(3LL, i, MOD) * modpow(3LL, j, MOD) % MOD * modpow(3LL, remaining, MOD) % MOD;
            
            long long valid_sequences = 0;
            if (i > 0) {
                valid_sequences = (valid_sequences + (i * modpow(3LL, j + remaining - 1, MOD) % MOD)) % MOD;
            }
            if (j > 0) {
                valid_sequences = (valid_sequences + (j * modpow(3LL, i + remaining - 1, MOD) % MOD)) % MOD;
            }
            if (remaining > 0) {
                valid_sequences = (valid_sequences + (remaining * modpow(3LL, i + j - 1, MOD) % MOD)) % MOD;
            }
            
            alice_wins = (alice_wins + (ways_to_choose * valid_sequences) % MOD) % MOD;
        }
    }
    
    cout << alice_wins << endl;
    
    return 0;
}