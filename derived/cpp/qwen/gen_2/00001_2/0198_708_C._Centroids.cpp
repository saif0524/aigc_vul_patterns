#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

vector<int> adj[MAXN];
int subtree_size[MAXN];
bool centroid_used[MAXN];
int n;

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int to : adj[v]) {
        if (to == p || centroid_used[to]) continue;
        dfs(to, v);
        subtree_size[v] += subtree_size[to];
    }
}

int find_centroid(int v, int p, int total_size) {
    for (int to : adj[v]) {
        if (to == p || centroid_used[to]) continue;
        if (subtree_size[to] > total_size / 2) {
            return find_centroid(to, v, total_size);
        }
    }
    return v;
}

vector<int> all_sizes;

void collect_sizes(int v, int p, int root) {
    all_sizes.push_back(subtree_size[v]);
    for (int to : adj[v]) {
        if (to == p || centroid_used[to]) continue;
        collect_sizes(to, v, root);
    }
}

int best_choice(int other_size, int total_size) {
    int best = 0;
    for (int x : all_sizes) {
        best = max(best, 2 * x <= total_size ? x : total_size - x);
    }
    return max(best, other_size);
}

void decompose(int v, int p, int root_size) {
    dfs(v, v);
    int centroid = find_centroid(v, v, subtree_size[v]);
    centroid_used[centroid] = true;

    all_sizes.clear();
    collect_sizes(centroid, centroid, root_size);
    int ans = best_choice(0, root_size);
    map<int, int> size_count;
    for (int x : all_sizes) size_count[x]++;

    for (int to : adj[centroid]) {
        if (centroid_used[to]) continue;

        int c = size_count[subtree_size[to]];
        if (c == 1) size_count.erase(subtree_size[to]);
        else size_count[subtree_size[to]]--;
        c = size_count[root_size - subtree_size[to]];
        if (c == 1) size_count.erase(root_size - subtree_size[to]);
        else size_count[root_size - subtree_size[to]]--;

        all_sizes.clear();
        collect_sizes(to, centroid, root_size);
        int max_branch = best_choice(subtree_size[to], root_size);

        all_sizes.push_back(subtree_size[to]);
        int max_without = best_choice(0, root_size);

        ans = max({ans, max_branch, max_without});

        size_count[subtree_size[to]]++;
        size_count[root_size - subtree_size[to]]++;
    }

    if (ans * 2 <= root_size) cout << "1 ";
    else cout << "0 ";

    for (int to : adj[centroid]) {
        if (centroid_used[to]) continue;
        decompose(to, centroid, subtree_size[to]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(1, 0, n);
}