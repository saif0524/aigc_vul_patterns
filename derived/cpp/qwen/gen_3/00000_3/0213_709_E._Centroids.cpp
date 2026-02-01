#include <bits/stdc++.h>
using namespace std;

const int maxn = 400005;
int n;
vector<int> adj[maxn];
int sz[maxn];
int centroid[maxn];
bool is_centroid[maxn];
int parent[maxn];

void calculate_sizes(int v, int p) {
    sz[v] = 1;
    for (int to : adj[v]) {
        if (to == p) continue;
        calculate_sizes(to, v);
        sz[v] += sz[to];
    }
}

int find_centroid(int v, int p, int total) {
    for (int to : adj[v]) {
        if (to == p) continue;
        if (sz[to] > total / 2) {
            return find_centroid(to, v, total);
        }
    }
    return v;
}

void decompose(int v) {
    calculate_sizes(v, -1);
    int c = find_centroid(v, -1, sz[v]);
    centroid[c] = parent[c] == -1 ? c : parent[c];
    is_centroid[c] = true;
    for (int to : adj[v]) {
        if (is_centroid[to]) continue;
        parent[to] = c;
        decompose(to);
    }
}

void dfs(int v, int p, int& total_size, int& max_subtree) {
    total_size++;
    int max_child = 0;
    for (int to : adj[v]) {
        if (to == p || is_centroid[to]) continue;
        int child_size = 0;
        dfs(to, v, child_size, max_subtree);
        max_child = max(max_child, child_size);
    }
    max_subtree = max(max_subtree, total_size - max_child - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(0);
    vector<int> result(n, 0);
    for(int c = 0; c < n; c++){
        if(is_centroid[c]){
            int max_subtree = 0;
            int total_size = 0;
            dfs(c, -1, total_size, max_subtree);
            int remaining = n - total_size - 1;
            if(max(remaining, max_subtree) <= n/2){
                result[c] = 1;
                continue;
            }
            for(int to : adj[c]){
                if(!is_centroid[to]){
                    int max_subtree_child = 0;
                    int total_size_child = 0;
                    dfs(to, c, total_size_child, max_subtree_child);
                    remaining = n - total_size_child - 1;
                    if(max(remaining, max_subtree_child) <= n/2){
                        result[c] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << (i == n - 1 ? '\n' : ' ');
    }
}