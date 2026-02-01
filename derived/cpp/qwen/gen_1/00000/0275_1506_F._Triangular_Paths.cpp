#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> r(n), c(n);
        for(auto &x: r) cin >> x;
        for(auto &x: c) cin >> x;
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        ll sum_r = accumulate(r.begin(), r.end(), 0LL);
        ll sum_c = accumulate(c.begin(), c.end(), 0LL);
        ll cost = abs(sum_r - sum_c);
        cout << cost << "\n";
    }
}