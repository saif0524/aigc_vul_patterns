#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> edges;
    vector<int> b = a;
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (b[i] > b[i + 1]) {
                edges.push_back({b[i], b[i + 1]});
                swap(b[i], b[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);

    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    int max_independent_set_size = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> independent_set;
        bool is_independent = true;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                independent_set.push_back(a[j]);
            }
        }

        for (size_t j = 0; j < independent_set.size(); ++j) {
            for (size_t k = j + 1; k < independent_set.size(); ++k) {
                bool found = false;
                for (int neighbor : adj[independent_set[j]]) {
                    if (neighbor == independent_set[k]) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    is_independent = false;
                    break;
                }
            }
            if (!is_independent) break;
        }

        if (is_independent) {
            max_independent_set_size = max(max_independent_set_size, (int)independent_set.size());
        }
    }

    cout << max_independent_set_size << endl;

    return 0;
}