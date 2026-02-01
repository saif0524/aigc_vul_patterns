#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<ll> sum_a(n+1, 0), sum_b(n+1, 0);
    for(int i=1;i<=n;i++){
        sum_a[i] = sum_a[i-1] + a[i-1];
        sum_b[i] = sum_b[i-1] + b[i-1];
    }
    ll max_sum = 0;
    for(int i=0;i<n;i++){
        ll cur_sum = sum_a[i+1] + sum_b[n] - sum_b[i] + (n-1-i)*b[i];
        max_sum = max(max_sum, cur_sum);
        cur_sum = sum_b[i+1] + sum_a[n] - sum_a[i] + (n-1-i)*a[i];
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum;
}