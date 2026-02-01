#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, p[N], x[N], sz[N];
vector<int> g[N];

void dfs(int u) {
    sz[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (x[i] > sz[i] * 5000 || (x[i] & 1)!= (sz[i] & 1)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    return 0;
}