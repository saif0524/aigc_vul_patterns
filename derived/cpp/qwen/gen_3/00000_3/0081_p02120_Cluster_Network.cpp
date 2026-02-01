#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int weight[MAXN];
int par[MAXN], sz[MAXN], perf[MAXN];
bool removed[MAXN];
int n, m;

int getParent(int x) {
    while (par[x] != x) x = par[x];
    return x;
}

void merge(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        perf[x] += perf[y];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> weight[i], perf[i] = weight[i], par[i] = i, sz[i] = 1;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=n; i>=1; i--){
        removed[i] = true;
        for(auto &j: adj[i]){
            if(!removed[j]) merge(i, j);
        }
        int p = getParent(i);
        cout << perf[p] << "\n";
    }
}