#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_N = 2005;

int n, k, m;
vector<int> friends[MAX_N];
vector<int> dislikes[MAX_N];
bitset<MAX_N> visited;

int dfs(int u, int mask) {
    visited[u] = true;
    for (int v : friends[u]) {
        if ((mask & (1 << v)) &&!visited[v]) {
            dfs(v, mask);
        }
    }
    return 0;
}

int main() {
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dislikes[u].push_back(v);
        dislikes[v].push_back(u);
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j : dislikes[i]) {
                if ((mask & (1 << j))!= 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (!valid) continue;

        visited.reset();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if ((mask & (1 << i))!= 0 &&!visited[i]) {
                dfs(i, mask);
                cnt++;
            }
        }
        if (cnt == 1) {
            ans = max(ans, __builtin_popcount(mask));
        }
    }
    cout << ans << endl;
    return 0;
}