#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

vector<int> adj[MAXN];
int subtree_size[MAXN];
int n;

void dfs1(int node, int parent) {
    subtree_size[node] = 1;
    for (int next : adj[node]) {
        if (next != parent) {
            dfs1(next, node);
            subtree_size[node] += subtree_size[next];
        }
    }
}

bool is_centroid(int node, int parent) {
    int mx = 0;
    for (int next : adj[node]) {
        if (next != parent) {
            mx = max(mx, subtree_size[next]);
        }
    }
    mx = max(mx, n - subtree_size[node]);
    return mx <= (n + 1) / 2;
}

int find_centroid(int node, int parent) {
    for (int next : adj[node]) {
        if (next != parent && subtree_size[next] > n / 2) {
            return find_centroid(next, node);
        }
    }
    return node;
}

void dfs2(int node, int parent, int prev_centroid) {
    if (is_centroid(node, prev_centroid)) {
        cout << 1 << " ";
    } else {
        cout << 0 << " ";
    }
    int original = subtree_size[parent];
    int centroid = find_centroid(node, parent);
    for (int next : adj[node]) {
        if (next != parent) {
            swap(subtree_size[next], subtree_size[parent]);
            subtree_size[parent] -= subtree_size[next];
            subtree_size[next] += subtree_size[parent];
            dfs2(next, node, centroid);
            swap(subtree_size[next], subtree_size[parent]);
            subtree_size[parent] += subtree_size[next];
            subtree_size[next] -= subtree_size[parent];
        }
    }
    subtree_size[parent] = original;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1, -1);
    cout << "\n";
    return 0;
}