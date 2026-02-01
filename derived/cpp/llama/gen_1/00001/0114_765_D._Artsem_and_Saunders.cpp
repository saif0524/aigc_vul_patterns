#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    vector<vector<int>> who(n);
    for (int i = 0; i < n; i++) {
        who[f[i] - 1].push_back(i);
    }
    vector<int> g(n);
    vector<int> h;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (!who[i].empty() && !used[i]) {
            h.push_back(i + 1);
            for (auto v : who[i]) {
                used[v] = true;
                g[v] = h.size();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            g[i] = h.size();
            h.push_back(f[i]);
            used[i] = true;
        }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[g[i] - 1] = f[i];
    }
    for (int i = 0; i < h.size(); i++) {
        if (res[i] != h[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << h.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << g[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < h.size(); i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}