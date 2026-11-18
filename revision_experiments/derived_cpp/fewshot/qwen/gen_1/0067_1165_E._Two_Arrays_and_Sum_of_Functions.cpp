#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<long long>());
    
    long long sum_a = 0, sum_b = 0, result = 0;
    for(int i=0;i<n;i++){
        sum_a = (sum_a + a[i]) % MOD;
        sum_b = (sum_b + (b[i] * (n-i))) % MOD;
        result = (result + (sum_a * b[i]) % MOD) % MOD;
    }
    
    result = (result + sum_b) % MOD;
    cout << result;
}