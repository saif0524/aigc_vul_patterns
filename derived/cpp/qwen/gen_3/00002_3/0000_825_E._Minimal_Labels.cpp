#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> inDegree(n+1, 0);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=n; ++i){
        if(inDegree[i] == 0){
            pq.push(i);
        }
    }
    vector<int> result(n);
    for(int i=0; i<n; ++i){
        int node = pq.top();
        pq.pop();
        result[i] = node;
        for(auto &neighbor : adj[node]){
            if(--inDegree[neighbor] == 0){
                pq.push(neighbor);
            }
        }
    }
    for(auto &x : result){
        cout << x << " ";
    }
    cout << "\n";
}