#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;
        vector<ll> x(m);
        for(auto &x: x) cin >> x;
        vector<ll> pref(n);
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + a[i];
        }
        ll total = pref[n-1];
        vector<pair<ll,int>> queries;
        for(int i=0;i<m;i++){
            queries.push_back({x[i], i});
        }
        sort(queries.begin(), queries.end());
        vector<ll> ans(m, -1);
        int idx = 0;
        for(auto &[q, pos]: queries){
            while(idx < n and q > 0){
                q -= a[idx];
                idx++;
            }
            if(q <= 0){
                ans[pos] = idx;
                continue;
            }
            if(total <=0) continue;
            ll rounds = q / total;
            q -= rounds * total;
            ans[pos] = rounds * n + idx;
            while(q > 0){
                q -= a[idx];
                idx++;
                if(idx == n){
                    idx = 0;
                }
            }
        }
        for(auto &x: ans){
            cout << x <<  ;
        }
        cout << "\n";
    }
}