#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<n; ++i){
        int cost = v[i];
        for(int j: adj[i]){
            cost += v[j];
        }
        pq.push({-cost, i});
    }
    vector<int> removed(n, 0);
    long long total_energy = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(removed[node]) continue;
        total_energy += cost;
        removed[node] = 1;
        for(int neighbor: adj[node]){
            if(removed[neighbor]) continue;
            int new_cost = v[neighbor];
            for(int j: adj[neighbor]){
                if(!removed[j]) new_cost += v[j];
            }
            pq.push({-new_cost, neighbor});
        }
    }
    cout << total_energy;
}