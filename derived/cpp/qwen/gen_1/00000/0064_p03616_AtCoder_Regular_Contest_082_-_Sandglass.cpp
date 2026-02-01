#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long X, K;
    cin >> X >> K;
    vector<long long> r(K);
    for(auto &x: r) cin >> x;
    long long Q;
    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    for(int i=0;i<Q;++i) cin >> queries[i].first >> queries[i].second;
    sort(r.begin(), r.end());
    vector<long long> upper_times;
    for(int i=0;i<=K;++i){
        if(i==0) upper_times.push_back(r[0]);
        else if(i==K) upper_times.push_back(1e18);
        else upper_times.push_back((r[i] + r[i-1])/2);
    }
    for(auto &[t, a] : queries){
        long long ans=a;
        for(int i=0;i<=K;++i){
            if(t < upper_times[i]){
                if(i%2==1) ans = X - ans;
                ans = max(0LL, ans - (t - r[max(0LL, i-1LL)]));
                break;
            }
        }
        cout << ans << "\n";
    }
}