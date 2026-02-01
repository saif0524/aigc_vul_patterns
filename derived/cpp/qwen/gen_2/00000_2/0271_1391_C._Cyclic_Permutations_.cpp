#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long fact = 1;
    for(int i = 1; i <= n; ++i){
        fact = (fact * i) % MOD;
    }
    long long inv2 = 500000004; // Modular inverse of 2 under modulo 10^9+7
    long long ans = (fact * inv2) % MOD;
    ans = (ans - n + MOD) % MOD;
    cout << ans;
}