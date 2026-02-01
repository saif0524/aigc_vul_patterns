#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    set<pair<int, int>> roads;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        roads.insert({a, b});
    }
    vector<vector<int>> ap(n+1);
    vector<int> tin(n+1, -1), low(n+1), visited(n+1, 0);
    int timer = 0;
    function<void(int, int)> dfs = [&](int v, int p){
        visited[v] = 1;
        tin[v] = low[v] = timer++;
        int children = 0;
        for(int to : adj[v]){
            if(to == p) continue;
            if(visited[to]){
                low[v] = min(low[v], tin[to]);
            }else{
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if(low[to] >= tin[v] && p != -1){
                    ap[v].push_back(to);
                }
                children++;
            }
        }
        if(p == -1 && children > 1){
            ap[v] = adj[v];
        }
    };
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    vector<pair<int, int>> ans;
    for(int i=1; i<=n; ++i){
        if(ap[i].size() >= 2){
            int to = ap[i][0];
            if(roads.find({i, to}) != roads.end()){
                ans.push_back({i, to});
                roads.erase({i, to});
            }else{
                ans.push_back({i, to});
                roads.insert({i, to});
            }
        }
    }
    if(ans.size() >= 1){
        cout << ans.size() << "\n";
        for(auto [a, b] : ans){
            cout << a << " " << b << "\n";
        }
        return 0;
    }
    int b = 0;
    for(int i=1; i<=n; ++i){
        if(visited[i] == 0) b++;
    }
    if(b > 0){
        cout << -1;
        return 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j : adj[i]){
            if(j > i){
                pair<int, int> road = {i, j};
                if(roads.find(road) == roads.end()){
                    ans.push_back({i, j});
                    roads.insert(road);
                }
            }
        }
    }
    int need = n - m + ans.size();
    if(need <= 1){
        cout << 0;
        return 0;
    }
    int added = 0;
    for(int i=1; i<=n && added < need-1; ++i){
        for(int j=i+1; j<=n && added < need-1; ++j){
            if(roads.find({i, j}) == roads.end()){
                ans.push_back({i, j});
                roads.insert({i, j});
                added++;
            }
        }
    }
    if(added < need-1){
        cout << -1;
        return 0;
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans){
        cout << a << " " << b << "\n";
    }
}