#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    ll min_moves = LLONG_MAX;
    vector<ll> suffix_sum(n+1, 0);
    for(int i=n-1; i>=0; --i) suffix_sum[i] = suffix_sum[i+1] + a[i];
    for(int i=0; i+k-1<n; ++i){
        int target = a[i+k-1];
        ll left_moves = 1LL * target * i - (suffix_sum[0] - suffix_sum[i]);
        ll right_moves = (suffix_sum[i+k] - suffix_sum[i+k-1]) - 1LL * target * (n-i-k);
        min_moves = min(min_moves, left_moves + right_moves);
    }
    cout << min_moves;
}