#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> D(N);
    for(auto &d: D) cin >> d;
    vector<vector<int>> adj(N);
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(N, -1);
    vector<long long> weights(M, 1);
    auto bfs = [&](int start){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
    };
    bfs(0);
    if(all_of(color.begin(), color.end(), [](int x){return x==0;})){
        cout << "-1";
        return 0;
    }
    for(int i=0;i<N;i++){
        if(!color[i]){
            for(int v: adj[i]){
                if(color[v]){
                    weights[find_if(adj[v].begin(), adj[v].end(), [u=i](int x){return x==v;}) - adj[v].begin()] = D[i];
                    break;
                }
            }
        }
    }
    string ans(N, 'W');
    for(int i=0;i<N;i++) if(color[i]) ans[i] = 'B';
    cout << ans << "\n";
    for(auto w: weights) cout << w << "\n";
}