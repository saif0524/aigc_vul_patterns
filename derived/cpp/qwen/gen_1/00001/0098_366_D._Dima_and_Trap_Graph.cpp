#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXM = 3010;

struct Edge {
    int u, v, l, r;
};

vector<Edge> edges;
vector<int> adj[MAXN];
int dp[MAXN][1000010];
bool visited[MAXN][1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        edges.push_back({u, v, l, r});
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    queue<pair<int, int>> q;
    for(int i=1;i<=1000000;i++){
        dp[1][i] = 1;
        q.push({1, i});
    }
    int max_loyalty = 0;
    while(!q.empty()){
        auto [node, x] = q.front();
        q.pop();
        if(visited[node][x]) continue;
        visited[node][x] = true;
        for(int idx : adj[node]){
            Edge e = edges[idx];
            int u = e.u, v = e.v, l = e.l, r = e.r;
            int next_node = (u == node) ? v : u;
            if(l <= x && x <= r){
                int new_loyalty = dp[node][x];
                for(int nx = l;nx<=r;nx++){
                    if(dp[next_node][nx] < new_loyalty){
                        dp[next_node][nx] = new_loyalty;
                        q.push({next_node, nx});
                    }
                }
                max_loyalty = max(max_loyalty, new_loyalty);
            }
        }
    }
    if(max_loyalty > 0){
        cout << max_loyalty;
    }
    else{
        cout << "Nice work, Dima!";
    }
}