#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(3*n+1);
        vector<pair<int, int>> edges;
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges.push_back({u, v});
        }
        vector<int> indSet;
        vector<bool> visited(3*n+1, false);
        for(int i=1; i<=3*n; i++){
            if(!visited[i]){
                indSet.push_back(i);
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto &neighbor : graph[node]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                        }
                    }
                }
            }
        }
        if(indSet.size() >= n){
            cout << "IndSet\n";
            for(int i=0; i<n; i++){
                cout << indSet[i] << (i==n-1?"\n":" ");
            }
            continue;
        }
        vector<int> match(3*n+1, -1);
        vector<bool> seen(3*n+1);
        function<bool(int)> dfs = [&](int u){
            if(seen[u]) return false;
            seen[u] = true;
            for(auto &v : graph[u]){
                if(match[v]==-1 || dfs(match[v])){
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
            return false;
        };
        int matchingSize = 0;
        for(int i=1; i<=3*n; i++){
            if(match[i]==-1){
                fill(seen.begin(), seen.end(), false);
                if(dfs(i)){
                    matchingSize++;
                }
            }
        }
        if(matchingSize >= n){
            cout << "Matching\n";
            vector<int> matchIndices;
            for(int i=0; i<m; i++){
                int u = edges[i].first, v = edges[i].second;
                if(match[u]==v || match[v]==u){
                    matchIndices.push_back(i+1);
                }
            }
            for(int i=0; i<n; i++){
                cout << matchIndices[i] << (i==n-1?"\n":" ");
            }
        }
        else{
            cout << "Impossible\n";
        }
    }
}