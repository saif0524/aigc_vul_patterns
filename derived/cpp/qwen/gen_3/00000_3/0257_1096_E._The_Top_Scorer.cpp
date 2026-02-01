#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 5005;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long inv(long long x) {
    return modPow(x, MOD - 2, MOD);
}

int main(){
    int p, s, r;
    cin >> p >> s >> r;
    vector<long long> dp(s+1,0);
    dp[0] = 1;
    for(int i=1; i<p; i++){
        vector<long long> new_dp(s+1,0);
        long long sum = 0;
        for(int j=0; j<=s; j++){
            sum += dp[j];
            sum %= MOD;
            if(j <= s - i)
                new_dp[j+i] = sum;
        }
        dp.swap(new_dp);
    }
    long long total = 0;
    for(int i=0; i<=s-r; i++){
        total = (total + dp[i]) % MOD;
    }
    long long wins = 0;
    for(int i=r+1; i<=s; i++){
        wins = (wins + dp[s-i]) % MOD;
    }
    long long ties = dp[s-r];
    if(ties > 0){
        wins = (wins + ties * modPow(2, MOD - 2, MOD)) % MOD;
    }
    if(total == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << (wins * inv(total)) % MOD << endl;
}