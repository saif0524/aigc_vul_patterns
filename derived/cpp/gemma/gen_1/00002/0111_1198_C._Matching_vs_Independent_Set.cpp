#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        // Try to find a matching of size n
        vector<int> matching;
        vector<bool> used(m, false);
        vector<bool> vertex_used(3 * n + 1, false);

        function<bool(int)> find_matching = [&](int k) {
            if (k == n) {
                return true;
            }

            for (int i = 0; i < m; ++i) {
                if (!used[i]) {
                    int u = edges[i].first;
                    int v = edges[i].second;

                    if (!vertex_used[u] && !vertex_used[v]) {
                        matching.push_back(i + 1);
                        vertex_used[u] = true;
                        vertex_used[v] = true;
                        used[i] = true;

                        if (find_matching(k + 1)) {
                            return true;
                        }

                        matching.pop_back();
                        vertex_used[u] = false;
                        vertex_used[v] = false;
                        used[i] = false;
                    }
                }
            }
            return false;
        };

        if (find_matching(0)) {
            cout << "Matching" << endl;
            for (int i = 0; i < n; ++i) {
                cout << matching[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            continue;
        }

        // Try to find an independent set of size n
        vector<int> independent_set;
        vector<bool> vertex_in_set(3 * n + 1, false);

        function<bool(int)> find_independent_set = [&](int k) {
            if (k == n) {
                return true;
            }

            for (int i = 1; i <= 3 * n; ++i) {
                if (!vertex_in_set[i]) {
                    bool can_add = true;
                    for (int j = 0; j < m; ++j) {
                        int u = edges[j].first;
                        int v = edges[j].second;
                        if ((u == i && vertex_in_set[v]) || (v == i && vertex_in_set[u])) {
                            can_add = false;
                            break;
                        }
                    }

                    if (can_add) {
                        independent_set.push_back(i);
                        vertex_in_set[i] = true;

                        if (find_independent_set(k + 1)) {
                            return true;
                        }

                        independent_set.pop_back();
                        vertex_in_set[i] = false;
                    }
                }
            }
            return false;
        };

        if (find_independent_set(0)) {
            cout << "IndSet" << endl;
            for (int i = 0; i < n; ++i) {
                cout << independent_set[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            continue;
        }

        cout << "Impossible" << endl;
    }

    return 0;
}