#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long total_energy = 0;
    priority_queue<pair<int, int>> pq;
    vector<bool> removed(n, false);
    for(int i=0; i<n; i++){
        pq.push({-v[i], i});
    }
    while(!pq.empty()){
        int part = pq.top().second;
        pq.pop();
        if(removed[part]) continue;
        removed[part] = true;
        int energy_cost = 0;
        for(int neighbor : adj[part]){
            if(!removed[neighbor]){
                energy_cost += v[neighbor];
            }
        }
        total_energy += energy_cost;
        for(int neighbor : adj[part]){
            if(!removed[neighbor]){
                v[neighbor] += v[part];
                pq.push({-v[neighbor], neighbor});
            }
        }
    }
    cout << total_energy;
}