#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
const int MAXM = 5e4 + 5;

struct Edge {
    int u, v, c, t, idx;
    bool operator<(const Edge &other) const {
        return t < other.t;
    }
};

int n, m;
vector<Edge> edges;
vector<vector<pair<int, int>>> graph(MAXN);
vector<vector<int>> color_graph(MAXN * 2);
vector<bool> visited(MAXN * 2);
vector<int> match(MAXN * 2, -1);

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (auto &v : color_graph[u]) {
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        edges.push_back({u, v, c, t, i + 1});
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
    }
    
    sort(edges.begin(), edges.end());
    
    int min_time = -1;
    vector<int> matching;
    for(auto &e : edges){
        if(min_time == -1) min_time = e.t;
        if(e.t != min_time) break;
        
        color_graph[e.c].emplace_back(e.u + n);
        color_graph[e.v].emplace_back(e.c);
        color_graph[e.u + n].emplace_back(e.c);
        color_graph[e.c].emplace_back(e.v);
        
        fill(visited.begin(), visited.begin() + 2 * n, false);
        if(dfs(e.c)){
            matching.push_back(e.idx);
        } else {
            color_graph[e.c].pop_back();
            color_graph[e.v].pop_back();
            color_graph[e.u + n].pop_back();
            color_graph[e.c].pop_back();
        }
    }
    
    bool valid = true;
    for(int c = 1; c <= 2 * n; ++c){
        fill(visited.begin(), visited.begin() + 2 * n, false);
        if(match[c] == -1) continue;
        if(!dfs(c)){
            valid = false;
            break;
        }
    }
    
    if(!valid){
        cout << "No";
    } else {
        cout << "Yes\n";
        cout << min_time << " " << matching.size() << "\n";
        for(auto &idx : matching){
            cout << idx << " ";
        }
    }
}