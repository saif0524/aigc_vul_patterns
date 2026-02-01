#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 200005;

int n, p[N], deg[N];
vector<int> adj[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i]) {
            adj[p[i]].push_back(i);
            deg[p[i]]++;
            deg[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (auto v : adj[u]) {
            deg[v]--;
            if (deg[v] == 1 && v != p[u]) {
                q.push(v);
            }
        }
    }

    if (ans.size() != n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto u : ans) {
            cout << u << endl;
        }
    }

    return 0;
}