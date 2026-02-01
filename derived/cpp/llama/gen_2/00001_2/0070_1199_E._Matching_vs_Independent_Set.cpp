#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> edges(m, 0);
        vector<int> used(3 * n, 0);
        vector<int> matching;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (!used[u] && !used[v]) {
                matching.push_back(i + 1);
                used[u] = 1;
                used[v] = 1;
                if (matching.size() == n) break;
            }
            edges[i] = max(u, v);
        }
        if (matching.size() == n) {
            cout << "Matching\n";
            for (int i : matching) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            vector<int> IndependentSet;
            for (int i = 0; i < 3 * n; ++i) {
                if (!used[i]) {
                    IndependentSet.push_back(i + 1);
                }
                if (IndependentSet.size() == n) break;
            }
            cout << "IndSet\n";
            for (int i : IndependentSet) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}