#include <bits/stdc++.h>
using namespace std;

const int MAXN = 710;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u, int prev) {
    for (int v : adj[u]) {
        if (v == prev) continue;
        if (vis[v]) {
            cout << "No\n";
            exit(0);
        }
        vis[v] = true;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (__gcd(a[i], a[j]) > 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vis[0] = true;
    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}