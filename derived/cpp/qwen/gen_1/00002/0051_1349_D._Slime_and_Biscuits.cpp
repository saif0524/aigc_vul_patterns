#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int modPow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        y >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for(int &x: a){
        cin >> x;
        total += x;
    }
    if(total == 0){
        cout << 0;
        return 0;
    }
    if(n == 2){
        cout << (1LL * a[0] * a[1]) % MOD;
        return 0;
    }
    vector<int> fact(total + 1, 1);
    vector<int> invFact(total + 1, 1);
    for(int i = 2; i <= total; i++){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invFact[i] = modPow(fact[i], MOD - 2);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == total){
            continue;
        }
        int ways = fact[total];
        for(int j = 0; j < n; j++){
            if(a[j] > 0){
                ways = (1LL * ways * invFact[a[j]]) % MOD;
            }
        }
        int contrib = (1LL * ways * (total - a[i]) * modPow(n - 1, total - a[i] - 1)) % MOD;
        ans = (ans + contrib) % MOD;
    }
    cout << ans;
}