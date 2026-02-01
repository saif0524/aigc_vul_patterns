#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m == 1){
        cout << "1\n1\n1\n2\n";
        return 0;
    }
    vector<int> color(n+1, -1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(color[i] == -1){
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v: adj[u]){
                    if(color[v] == color[u]){
                        cout << "-1";
                        return 0;
                    }
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<int> a, b;
    for(int i=1;i<=n;i++){
        if(color[i] == 0) a.push_back(i);
        else b.push_back(i);
    }
    if(a.size() == 0 || b.size() == 0){
        cout << "-1";
        return 0;
    }
    cout << a.size() << "\n";
    for(auto x: a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for(auto x: b) cout << x << " ";
}