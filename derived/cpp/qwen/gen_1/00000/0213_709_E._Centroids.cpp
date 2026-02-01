#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400010;

vector<int> adj[MAXN];
int subTreeSize[MAXN];
bool centroid[MAXN];
int n, parent[MAXN];

void dfs(int u, int p) {
    parent[u] = p;
    subTreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subTreeSize[u] += subTreeSize[v];
        }
    }
}

int findCentroid(int u, int size, int p) {
    for (int v : adj[u]) {
        if (v != p && !centroid[v] && subTreeSize[v] > size / 2) {
            return findCentroid(v, size, u);
        }
    }
    return u;
}

void decompose(int u, int p) {
    dfs(u, -1);
    int c = findCentroid(u, subTreeSize[u], -1);
    centroid[c] = true;
    for (int v : adj[c]) {
        if (!centroid[v]) {
            decompose(v, c);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(0, -1);
    vector<int> result(n, 0);
    for(int i=0;i<n;i++){
        int maxSize = 0;
        for(int v : adj[i]){
            if(!centroid[v]){
                maxSize = max(maxSize, subTreeSize[v]);
            }
        }
        maxSize = max(maxSize, n - subTreeSize[i]);
        if(maxSize <= (n+1)/2){
            result[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}