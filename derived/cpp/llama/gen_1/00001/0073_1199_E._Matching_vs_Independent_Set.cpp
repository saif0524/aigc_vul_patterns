#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 300010;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> e(m);
        vector<bool> vis(3 * n + 1);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            e[i] = make_pair(u, v);
        }

        vector<int> match;
        for (int i = 0; i < m; ++i) {
            if (!vis[e[i].first] && !vis[e[i].second]) {
                match.push_back(i + 1);
                vis[e[i].first] = true;
                vis[e[i].second] = true;
            }
        }

        if (match.size() >= n) {
            cout << "Matching" << endl;
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << match[i];
            }
            cout << endl;
        } else {
            vector<int> ind;
            for (int i = 1; i <= 3 * n; ++i) {
                if (!vis[i]) ind.push_back(i);
            }
            cout << "IndSet" << endl;
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << ind[i];
            }
            cout << endl;
        }
    }

    return 0;
}