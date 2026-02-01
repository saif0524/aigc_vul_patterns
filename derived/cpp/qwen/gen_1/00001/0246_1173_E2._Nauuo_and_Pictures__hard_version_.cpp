#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modPow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long a) {
    return modPow(a, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<long long> w(n);
    for(long long &x : w) cin >> x;
    
    long long total_weight = accumulate(w.begin(), w.end(), 0LL);
    vector<long long> dp(m+1, 0);
    dp[0] = 1;
    for(int j=1; j<=m; j++){
        for(int i=1; i<=j; i++){
            dp[i] = (dp[i] * (total_weight - i + 1) - dp[i-1] * (total_weight - j) + MOD) % MOD;
            dp[i] = (dp[i] * modInverse(i * (total_weight - j + 1)) + MOD) % MOD;
        }
    }
    
    vector<long long> like_dp(m+1, 0), dislike_dp(m+1, 0);
    like_dp[0] = 1;
    for(int j=1; j<=m; j++){
        for(int i=1; i<=j; i++){
            like_dp[i] = (like_dp[i] * (total_weight - i + 1) - like_dp[i-1] * (total_weight - j) + MOD) % MOD;
            like_dp[i] = (like_dp[i] * modInverse(i * (total_weight - j + 1)) + MOD) % MOD;
        }
    }
    
    for(int j=0; j<=m; j++){
        dislike_dp[j] = (dp[j] - like_dp[j] + MOD) % MOD;
    }
    
    vector<long long> like_count(n, 0);
    for(int i=0; i<n; i++){
        if(a[i]){
            for(int j=1; j<=min(m, (int)w[i]); j++){
                like_count[i] = (like_count[i] + like_dp[j]) % MOD;
            }
        }
    }
    
    vector<long long> dislike_count(n, 0);
    for(int i=0; i<n; i++){
        if(!a[i]){
            for(int j=1; j<=min(m, (int)w[i]); j++){
                dislike_count[i] = (dislike_count[i] + dislike_dp[j]) % MOD;
            }
        }
    }
    
    vector<long long> expected_weight(n);
    for(int i=0; i<n; i++){
        long long new_weight = w[i] + like_count[i] - dislike_count[i];
        expected_weight[i] = new_weight * modInverse(total_weight + m) % MOD;
    }
    
    for(int i=0; i<n; i++){
        cout << expected_weight[i] << " \n"[i == n-1];
    }
}