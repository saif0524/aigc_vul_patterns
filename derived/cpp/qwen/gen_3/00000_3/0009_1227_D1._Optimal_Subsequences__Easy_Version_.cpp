#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    int m;
    cin >> m;
    vector<pair<int,int>> queries(m);
    for(auto &q : queries) cin >> q.first >> q.second;
    
    for(auto &[k, pos] : queries){
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int i=0; i<n; ++i){
            pq.push(a[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<long long> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans[pos-1] << "\n";
    }
    return 0;
}