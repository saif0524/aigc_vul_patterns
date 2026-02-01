#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 200005;

vector<int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int u, int a, int b) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (v != a && !visited[v]) {
            dfs(v, a, b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        a--; b--;

        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(visited, false, sizeof(visited));
        dfs(a, a, b);
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (i != a && i != b && visited[i]) {
                count1++;
            }
        }

        memset(visited, false, sizeof(visited));
        dfs(b, a, b);
        int count2 = 0;
        for (int i = 0; i < n; i++) {
            if (i != a && i != b && visited[i]) {
                count2++;
            }
        }

        long long result = (long long)count1 * (n - 1 - count1 - count2);
        cout << result << '\n';
    }

    return 0;
}