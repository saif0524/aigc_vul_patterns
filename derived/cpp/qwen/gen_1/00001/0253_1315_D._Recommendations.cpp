#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> t(n);
    for(auto &x: a) cin >> x;
    for(auto &x: t) cin >> x;
    priority_queue<pair<long long, long long>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({-a[i], -t[i]});
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        auto [cnt, cost] = pq.top();
        cnt = -cnt;
        cost = -cost;
        pq.pop();
        if(i > 0 && cnt == prev_val){
            cnt++;
            ans += cost;
        }
        prev_val = cnt;
        pq.push({-cnt, -cost});
    }
    cout << ans;
}