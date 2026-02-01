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
        vector<pair<int, int>> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].first >> edges[i].second;
        }
        vector<int> indegree(3*n+1, 0);
        for(auto [u, v] : edges){
            indegree[u]++;
            indegree[v]++;
        }
        vector<int> leaves;
        for(int i=1;i<=3*n;i++){
            if(indegree[i] == 0){
                leaves.push_back(i);
            }
        }
        if((int)leaves.size() >= n){
            cout << "IndSet\n";
            for(int i=0;i<n;i++){
                cout << leaves[i] << " ";
            }
            cout << "\n";
            continue;
        }
        vector<int> match(3*n+1, -1);
        vector<bool> visited(3*n+1, false);
        function<bool(int)> dfs = [&](int u)->bool{
            if(visited[u]) return false;
            visited[u] = true;
            for(int i=0;i<m;i++){
                auto [v, w] = edges[i];
                if(v == u){
                    if(match[w] == -1 || dfs(match[w])){
                        match[w] = i+1;
                        return true;
                    }
                }
                else if(w == u){
                    if(match[v] == -1 || dfs(match[v])){
                        match[v] = i+1;
                        return true;
                    }
                }
            }
            return false;
        };
        int cnt = 0;
        for(int i=1;i<=3*n;i++){
            if(!visited[i]){
                if(dfs(i)){
                    cnt++;
                }
            }
        }
        if(cnt >= n){
            cout << "Matching\n";
            for(int i=1;i<=3*n;i++){
                if(match[i] != -1){
                    cout << match[i] << " ";
                    cnt--;
                    if(cnt == 0) break;
                }
            }
            cout << "\n";
        }
        else{
            cout << "Impossible\n";
        }
    }
}