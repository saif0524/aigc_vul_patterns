#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long I;
    cin >> n >> I;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    I *= 8;
    int ans = n;
    for(int i=0; i<n; ++i){
        int l = a[i];
        auto it = upper_bound(a.begin(), a.end(), l);
        int cur = i;
        for(int j=i; j<n; ++j){
            it = upper_bound(it, a.end(), a[j]);
            int r = a[j];
            int k = 1;
            if(it != a.end()) k = 32 - __builtin_clz(it - a.begin() - (j - i) + cur);
            if(1LL * k * (n - cur) <= I){
                ans = min(ans, cur + (n - (it - a.begin())));
            }
            cur = it - a.begin();
        }
        break;
    }
    cout << ans;
}