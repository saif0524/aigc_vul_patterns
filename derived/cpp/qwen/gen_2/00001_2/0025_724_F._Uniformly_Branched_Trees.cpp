#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXD = 11;
const int MAXMOD = 1e9 + 9;

int n, d, mod;
long long dp[MAXN][MAXD];

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> mod;
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= d; j++){
            dp[i][j] = 0;
            for(int k = 0; k < j; k++){
                long long coeff = power(j, k, mod);
                dp[i][j] = (dp[i][j] + dp[i-1][j-k] * coeff) % mod;
            }
            if(i >= d){
                dp[i][j] = (dp[i][j] + dp[i-d+1][j-1] * (d-1)) % mod;
            }
        }
    }
    
    long long sum = 0;
    for(int j = 0; j <= d; j++){
        sum = (sum + dp[n][j]) % mod;
    }
    
    long long inv_sum = power(sum, mod - 2, mod);
    long long ans = dp[n][1] * inv_sum % mod;
    
    cout << ans << "\n";
}