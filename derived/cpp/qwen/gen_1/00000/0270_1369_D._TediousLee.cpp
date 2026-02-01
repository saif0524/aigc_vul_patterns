#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long mod_exp(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n <= 2){
            cout << 0 << "\n";
            continue;
        }
        long long ans = (mod_exp(3, n-2) * 4) % MOD;
        cout << ans << "\n";
    }
}