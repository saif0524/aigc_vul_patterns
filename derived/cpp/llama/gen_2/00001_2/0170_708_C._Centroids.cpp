#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 400005;
vector<int> graph[MAX_N];
int n, size[MAX_N], max_size[MAX_N];
bool can_be_centroid[MAX_N];

void dfs(int u, int p) {
    size[u] = 1;
    max_size[u] = 0;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        size[u] += size[v];
        max_size[u] = max(max_size[u], size[v]);
    }
}

bool check(int u) {
    dfs(u, u);
    return 2 * max_size[u] <= n;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        can_be_centroid[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[j].clear();
        }

        for (int j = 1; j <= n; j++) {
            for (int k : graph[j]) {
                if (j < k) {
                    if (j != i && k != i) {
                        graph[j].push_back(k);
                    }
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            if (j != i) {
                graph[i].push_back(j);
            }
        }

        if (check(i)) {
            can_be_centroid[i] = true;
        }

        for (int v : graph[i]) {
            for (int j = 1; j <= n; j++) {
                graph[j].clear();
            }

            for (int j = 1; j <= n; j++) {
                for (int k : graph[j]) {
                    if (j < k) {
                        if (j != i && k != i) {
                            graph[j].push_back(k);
                        } else if (j == i && k == v) {
                            // do nothing
                        } else {
                            graph[j].push_back(k);
                        }
                    }
                }
            }

            for (int j = 1; j <= n; j++) {
                if (j != i && j != v) {
                    graph[i].push_back(j);
                    graph[v].push_back(j);
                }
            }

            if (check(i)) {
                can_be_centroid[i] = true;
            }

            if (check(v)) {
                can_be_centroid[v] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << can_be_centroid[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}