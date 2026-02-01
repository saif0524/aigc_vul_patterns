#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<long long>());
    long long prefix_a[n];
    memset(prefix_a, 0, sizeof(prefix_a));
    prefix_a[0] = a[0];
    for(int i=1;i<n;i++){
        prefix_a[i] = (prefix_a[i-1] + a[i])%MOD;
    }
    long long suffix_a[n];
    memset(suffix_a, 0, sizeof(suffix_a));
    suffix_a[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suffix_a[i] = (suffix_a[i+1] + a[i])%MOD;
    }
    long long ans = 0;
    long long prefix_b = 0;
    long long suffix_b = 0;
    for(int i=0;i<n;i++){
        prefix_b = (prefix_b + b[i])%MOD;
        suffix_b = (suffix_b + b[n-i-1])%MOD;
        long long part1 = (prefix_a[i] * prefix_b)%MOD;
        long long part2 = (suffix_a[n-i-1] * suffix_b)%MOD;
        ans = (ans + part1)%MOD;
        ans = (ans + part2)%MOD;
        ans = (ans - (a[i]*b[i])%MOD)%MOD;
        ans = (ans + MOD)%MOD;
    }
    cout << ans%MOD << "\n";
}