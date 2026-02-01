#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    vector<int> depth(n+1, 0);
    vector<int> leaves(n+1, 0);
    function<void(int)> dfs = [&](int node){
        if(adj[node].empty()){
            leaves[node] = 1;
            return;
        }
        for(int child : adj[node]){
            depth[child] = depth[node] + 1;
            dfs(child);
            leaves[node] += leaves[child];
        }
    };
    dfs(1);
    vector<int> q(n+1, 0);
    function<void(int,int,int)> dfs2 = [&](int node, int parent, int max_up){
        int max_leaves = 0;
        for(int child : adj[node]){
            if(depth[node] - depth[child] > k){
                int leaves_below = leaves[child];
                q[node] += leaves_below;
                max_leaves = max(max_leaves, leaves_below);
            }
        }
        for(int child : adj[node]){
            if(depth[node] - depth[child] > k){
                leaves[child] = q[node] - leaves[child] + max_up;
            }
            dfs2(child, node, max(max_up, leaves[node] - leaves[child]));
        }
    };
    dfs2(1, 0, 0);
    int result = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].empty()){
            result = max(result, leaves[i]);
        }
    }
    cout << result << "\n";
}