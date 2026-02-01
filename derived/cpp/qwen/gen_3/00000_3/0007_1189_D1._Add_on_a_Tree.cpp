#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int leaves = 0;
    for(int i=0;i<n;++i){
        if(adj[i].size() == 1){
            ++leaves;
        }
    }
    if(leaves >= 3){
        cout << "NO";
    } else {
        cout << "YES";
    }
}