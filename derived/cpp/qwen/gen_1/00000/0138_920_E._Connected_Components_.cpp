#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int v, int &sz) {
    visited[v] = true;
    sz++;
    for (int to : adj[v]) {
        if (!visited[to]) {
            dfs(to, sz);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            bool found = false;
            for(const auto &[a, b] : edges){
                if((a == i && b == j) || (a == j && b == i)){
                    found = true;
                    break;
                }
            }
            if(!found){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> component_sizes;
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            int sz = 0;
            dfs(i, sz);
            component_sizes.push_back(sz);
        }
    }
    sort(component_sizes.begin(), component_sizes.end());
    cout << component_sizes.size() << "\n";
    for(int sz : component_sizes){
        cout << sz << " ";
    }
}