#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        vector<pair<long long,long long>> segs;
        int miss = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == -1){
                while(i < n && a[i] == -1){
                    ++miss;
                    ++i;
                }
                segs.emplace_back(a[i - miss - 1], a[i]);
            }
        }
        long long m = 1e18, k = 0;
        for(auto [l, r]: segs){
            if(l > r) swap(l, r);
            long long diff = abs(l - r);
            long long mm = (diff + miss - 1) / miss;
            if(mm < m){
                m = mm;
                k = (l + r) / 2;
            }
            else if(mm == m){
                k = min(k, (l + r) / 2);
            }
        }
        cout << m << " " << k << "\n";
    }
}