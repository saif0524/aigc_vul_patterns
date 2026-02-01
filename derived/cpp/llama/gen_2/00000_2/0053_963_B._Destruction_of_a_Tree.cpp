#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
    }

    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);

        for (int u : adj[v]) {
            degree[u]--;
            if (degree[u] % 2 == 0) {
                q.push(u);
            }
        }
    }

    if (ans.size() == n) {
        cout << "YES" << endl;
        for (int v : ans) {
            cout << v + 1 << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}