#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first;
        --edges[i].second;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        g[edges[i].first].push_back(i);
        g[edges[i].second].push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i]!= -1) {
            ++cnt;
        }
    }

    if (cnt % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> used(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) {
            used[i] = 1;
            for (int j : g[i]) {
                ans.push_back(j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == 1) {
            if (used[i]) {
                cout << -1 << '\n';
                return 0;
            }
            used[i] = 1;
            for (int j : g[i]) {
                ans.push_back(j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            if (used[i]) {
                cout << -1 << '\n';
                return 0;
            }
            used[i] = 1;
            for (int j : g[i]) {
                ans.push_back(j);
            }
        }
    }

    cout << ans.size() / 2 << '\n';
    for (int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] + 1 << '\n';
    }

    return 0;
}