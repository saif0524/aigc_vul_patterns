#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for(auto &x: a){
        cin >> x;
        sum += x;
    }
    if(sum == 0){
        cout << 0;
        return 0;
    }
    vector<long long> fact(sum + 1, 1);
    vector<long long> inv_fact(sum + 1, 1);
    for(long long i = 2; i <= sum; ++i){
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv_fact[i - 1] * pow(i, MOD - 2, MOD) % MOD;
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 0) continue;
        long long curr = 0;
        for(int j = 1; j <= a[i] - 1; ++j){
            curr = (curr + (fact[sum - 1] * inv_fact[j] % MOD * inv_fact[sum - 1 - j] % MOD * j % MOD * (n - 1) % MOD) % MOD) % MOD;
        }
        ans = (ans + curr * inv_fact[a[i]] % MOD * inv_fact[sum - a[i]] % MOD) % MOD;
    }
    ans = ans * inv_fact[n - 1] % MOD;
    cout << ans;
}