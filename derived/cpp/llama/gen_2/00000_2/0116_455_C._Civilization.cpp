#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5 + 10;

vector<int> adj[MAX_N];
int depth[MAX_N], parent[MAX_N];

void bfs(int start, vector<int>& leaves) {
    queue<int> q;
    q.push(start);
    depth[start] = 0;
    parent[start] = -1;
    int maxDepth = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
                maxDepth = max(maxDepth, depth[v]);
            }
        }
    }

    leaves.clear();
    for (int i = 1; i <= start; ++i) {
        if (depth[i] == maxDepth) {
            leaves.push_back(i);
        }
    }
}

int maxDist[MAX_N];

int findMaxDist(int start) {
    vector<int> leaves;
    bfs(start, leaves);

    int res = 0;
    for (int i = 0; i < leaves.size(); ++i) {
        vector<int> leaf1;
        bfs(leaves[i], leaf1);

        for (int j = 0; j < leaf1.size(); ++j) {
            int dist = depth[leaves[i]] + depth[leaf1[j]];
            res = max(res, dist);
        }
    }

    maxDist[start] = res;
    return res;
}

int UnionFind[MAX_N];

int findRoot(int x) {
    if (UnionFind[x] == x) {
        return x;
    } else {
        return UnionFind[x] = findRoot(UnionFind[x]);
    }
}

void merge(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);

    if (rootX != rootY) {
        adj[rootX].push_back(rootY);
        adj[rootY].push_back(rootX);

        for (int i = 1; i <= max(rootX, rootY); ++i) {
            if (findRoot(i) == rootY) {
                UnionFind[i] = rootX;
            }
        }

        int root = findRoot(rootX);

        maxDist[root] = max(maxDist[rootX], maxDist[rootY]);
        maxDist[root] = max(maxDist[root], findMaxDist(root) + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        depth[i] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        UnionFind[i] = i;
        if (depth[i] == -1) {
            findRoot(i);
            maxDist[i] = findMaxDist(i);
        }
    }

    for (int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type >> x;

        if (type == 1) {
            cout << maxDist[findRoot(x)] << '\n';
        } else {
            cin >> y;
            merge(x, y);
        }
    }

    return 0;
}