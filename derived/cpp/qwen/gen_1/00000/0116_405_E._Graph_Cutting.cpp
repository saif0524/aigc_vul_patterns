#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> edges;
    vector<int> degree(n, 0);
    for(int i=0;i<n;i++){
        degree[i] = adj[i].size();
        for(auto& it : adj[i]){
            if(it > i){
                edges.push_back({i, it});
            }
        }
    }
    int odd_cnt = 0;
    for(int d : degree){
        if(d % 2 == 1){
            odd_cnt++;
        }
    }
    if(odd_cnt != 0 && odd_cnt != 2){
        printf("No solution\n");
        return 0;
    }
    vector<int> path;
    function<void(int, int)> dfs = [&](int node, int prev){
        while(!adj[node].empty()){
            int next = adj[node].back();
            adj[node].pop_back();
            for(auto& it : adj[next]){
                if(it == node){
                    adj[next].erase(it);
                    break;
                }
            }
            dfs(next, node);
        }
        path.push_back(node);
    };
    int start = -1;
    for(int i=0;i<n;i++){
        if(degree[i] % 2 == 1){
            start = i;
            break;
        }
    }
    if(start == -1){
        start = 0;
    }
    dfs(start, -1);
    reverse(path.begin(), path.end());
    if(path.size() != m + 1){
        printf("No solution\n");
        return 0;
    }
    for(int i=0;i<(int)path.size()-2;i+=2){
        printf("%d %d %d\n", path[i]+1, path[i+1]+1, path[i+2]+1);
    }
    return 0;
}