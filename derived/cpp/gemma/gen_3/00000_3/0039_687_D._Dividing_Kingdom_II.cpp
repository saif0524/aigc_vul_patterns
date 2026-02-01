#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(u, v, w);
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--;

        vector<tuple<int, int, int>> remaining_edges;
        for (int j = 0; j < m; ++j) {
            if (j >= l && j <= r) {
                remaining_edges.push_back(edges[j]);
            }
        }

        int min_hardness = -1;

        for (int j = 0; j < (1 << n); ++j) {
            vector<int> group1;
            vector<int> group2;
            for (int k = 0; k < n; ++k) {
                if ((j >> k) & 1) {
                    group1.push_back(k + 1);
                } else {
                    group2.push_back(k + 1);
                }
            }

            int max_edge_in_same_group = -1;
            for (auto& edge : remaining_edges) {
                int u = get<0>(edge);
                int v = get<1>(edge);
                int w = get<2>(edge);

                bool u_in_group1 = false;
                bool v_in_group1 = false;

                for (int city : group1) {
                    if (city == u) u_in_group1 = true;
                    if (city == v) v_in_group1 = true;
                }

                if (u_in_group1 == v_in_group1) {
                    max_edge_in_same_group = max(max_edge_in_same_group, w);
                }
            }

            if (min_hardness == -1 || (max_edge_in_same_group != -1 && max_edge_in_same_group < min_hardness)) {
                min_hardness = max_edge_in_same_group;
            }
        }

        cout << min_hardness << endl;
    }

    return 0;
}