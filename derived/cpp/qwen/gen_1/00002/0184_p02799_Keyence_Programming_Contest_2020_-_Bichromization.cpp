#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> D(N);
    for(auto &d: D) cin >> d;
    vector<vector<int>> edges(N);
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> color(N, -1);
    vector<long long> dist(N, INF);
    bool ok = false;
    queue<int> q;
    for(int start=0;start<N && !ok;start++){
        if(color[start] != -1) continue;
        q.push(start);
        color[start] = 0;
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &nxt: edges[node]){
                if(color[nxt] == -1){
                    color[nxt] = color[node] ^ 1;
                    dist[nxt] = dist[node] + 1;
                    q.push(nxt);
                }
                else{
                    if(color[nxt] == color[node]) ok = true;
                }
            }
        }
    }
    for(int i=0;i<N && !ok;i++){
        if(color[i] == -1) ok = true;
    }
    if(ok){
        cout << "-1";
        return 0;
    }
    for(int i=0;i<N;i++){
        if(color[i] == 0){
            for(auto &nxt: edges[i]){
                if(D[i] != dist[nxt]){
                    ok = true;
                    break;
                }
            }
        }
        else{
            for(auto &nxt: edges[i]){
                if(D[nxt] != dist[i]){
                    ok = true;
                    break;
                }
            }
        }
    }
    if(ok){
        cout << "-1";
        return 0;
    }
    string res(N, 'B');
    for(int i=0;i<N;i++){
        if(color[i] == 0) res[i] = 'W';
    }
    vector<long long> weights(M, 1);
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        weights[i] = min(D[u], D[v]);
    }
    cout << res << "\n";
    for(auto &w: weights){
        cout << w << "\n";
    }
}