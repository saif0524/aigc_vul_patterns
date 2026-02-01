#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> prefix_sum(n+1, 0);
    for(int i=0;i<n;i++) prefix_sum[i+1] = (prefix_sum[i] + a[i]) % MOD;
    ll result = 0;
    for(int i=0;i<n;i++){
        result = (result + b[i] * (prefix_sum[n] - prefix_sum[i])) % MOD;
    }
    cout << result;
}