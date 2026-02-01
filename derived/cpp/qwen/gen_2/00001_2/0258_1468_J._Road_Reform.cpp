#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, long long>>> adj(n);
        for(int i=0;i<m;i++){
            int x, y;
            long long s;
            cin >> x >> y >> s;
            x--, y--;
            adj[x].emplace_back(y, s);
            adj[y].emplace_back(x, s);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<bool> vis(n, false);
        pq.emplace(0, 0);
        long long total_changes = 0;
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            if(cost < k){
                total_changes += k - cost;
            }
            for(auto [neigh, weight] : adj[node]){
                if(!vis[neigh]){
                    pq.emplace(min(k, weight), neigh);
                }
            }
        }
        cout << total_changes << "\n";
    }
}