#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int color[MAXN];
bool visited[MAXN];
int n, k;

bool dfs(int node, int c) {
    if (visited[node]) return true;
    visited[node] = true;
    color[node] = c;
    bool all_colors_used = false;
    int used_colors[5] = {0};
    used_colors[c] = 1;
    for (int next : adj[node]) {
        if (!visited[next]) {
            if (!dfs(next, (c % k) + 1)) return false;
            used_colors[color[next]] = 1;
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (used_colors[i] == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(dfs(1, 1)){
        cout << "Yes\n";
        for(int i = 1; i <= n; ++i){
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    else{
        cout << "No\n";
    }
}