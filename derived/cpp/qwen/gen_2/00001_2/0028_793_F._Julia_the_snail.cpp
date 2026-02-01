#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ropes(m);
    for(auto &r : ropes) cin >> r.first >> r.second;
    sort(ropes.begin(), ropes.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;
    });
    vector<int> max_reach(n+1, 0);
    int current_max = 0;
    for(int i=1;i<=n;i++){
        while(!ropes.empty() && ropes.front().first <= i){
            current_max = max(current_max, ropes.front().second);
            ropes.erase(ropes.begin());
        }
        max_reach[i] = current_max;
        current_max = max(current_max, max_reach[i-1]);
    }
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans = x;
        for(int i=x;i<=y;){
            ans = max(ans, max_reach[i]);
            if(max_reach[i] <= i) break;
            i = max_reach[i];
        }
        cout << ans << "\n";
    }
}