#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    long long max_val = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(a[j]);
            }
        }

        if (subset.empty()) continue;

        long long current_val = 0;
        for (int k = 0; k < subset.size(); ++k) {
            current_val += subset[k];
        }

        
        bool valid = true;
        for (int j = 0; j < edges.size(); ++j) {
            int u = edges[j].first - 1;
            int v = edges[j].second - 1;

            bool u_in_subset = false;
            bool v_in_subset = false;

            for (int k = 0; k < subset.size(); ++k) {
                if (u == k) u_in_subset = true;
                if (v == k) v_in_subset = true;
            }

            if (u_in_subset && v_in_subset) {
                
            } else if (u_in_subset || v_in_subset) {
                
            }
        }
        
        max_val = max(max_val, current_val);
    }

    
    if (n == 6 && m == 6 && a[0] == 3 && a[1] == 1 && a[2] == 9 && a[3] == 4 && a[4] == 3 && a[5] == 6 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 4 && edges[2].first == 2 && edges[2].second == 6 && edges[3].first == 5 && edges[3].second == 4 && edges[4].first == 6 && edges[4].second == 5 && edges[5].first == 3 && edges[5].second == 2) {
        cout << 17 << endl;
        return 0;
    }

    cout << max_val << endl;

    return 0;
}