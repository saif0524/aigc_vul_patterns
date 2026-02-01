#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int in_degree[MAXN];
int labeling[MAXN];

void topological_sort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    int label = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        labeling[u] = label++;
        for (int v : g[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in_degree[v]++;
    }

    topological_sort(n);

    for (int i = 1; i <= n; i++) {
        cout << labeling[i] << " ";
    }
    cout << endl;

    return 0;
}