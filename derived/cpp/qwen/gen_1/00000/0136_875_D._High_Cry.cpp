#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int max_bit = 0;
    for(int i=0; i<n; ++i){
        max_bit = max(max_bit, 31 - __builtin_clz(a[i]|1));
    }
    vector<int> count(1 << (max_bit+1), 0);
    for(int i=0; i<n; ++i){
        count[a[i]]++;
    }
    for(int i=1; i<(1 << (max_bit+1)); ++i){
        count[i] += count[i-1];
    }
    long long ans = 0;
    for(int i=0; i<n; ++i){
        int c = count[a[i]-1];
        int mask = 0;
        for(int j=0; j<=max_bit; ++j){
            if(((a[i] >> j) & 1) == 0){
                mask |= (1 << j);
                c -= count[mask];
            }
        }
        ans += i - c;
    }
    cout << ans;
}