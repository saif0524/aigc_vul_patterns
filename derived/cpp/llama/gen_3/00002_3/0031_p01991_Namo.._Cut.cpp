#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> graph[MAX_N];
int depth[MAX_N];
int parent[MAX_N][20];
int maxDepth = 0;

void dfs(int node, int par, int dep) {
    depth[node] = dep;
    parent[node][0] = par;

    for (int i = 1; i <= 18; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (int child : graph[node]) {
        if (child != par) {
            dfs(child, node, dep + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    int diff = depth[b] - depth[a];

    for (int i = 18; i >= 0; i--) {
        if (diff & (1 << i)) {
            b = parent[b][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = 18; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int countCutEdges(int a, int b) {
    int lcaNode = lca(a, b);
    int cutEdges = depth[a] + depth[b] - 2 * depth[lcaNode];

    return cutEdges;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> edgeWeights;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int root = 1;
    dfs(root, root, 0);

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;

        int cutEdges = countCutEdges(a, b);
        cout << cutEdges << "\n";
    }

    return 0;
}