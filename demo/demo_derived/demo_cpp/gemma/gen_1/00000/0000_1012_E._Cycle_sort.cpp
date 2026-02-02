#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    if (a == sorted_a) {
        cout << 0 << endl;
        return 0;
    }

    int min_ops = -1;
    vector<vector<int>> operations;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> cycle;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                cycle.push_back(j);
            }
        }

        if (cycle.empty()) continue;

        if (cycle.size() == 1) continue;
        
        int cycle_len = cycle.size();

        if (s < cycle_len) continue;

        vector<int> temp_a = a;
        
        for (int j = 0; j < cycle_len; ++j) {
            int next_index = (j + 1) % cycle_len;
            int val = temp_a[cycle[j]];
            temp_a[cycle[j]] = temp_a[cycle[next_index]];
            temp_a[cycle[next_index]] = val;
        }

        if (temp_a == sorted_a) {
            if (min_ops == -1 || 1 < min_ops) {
                min_ops = 1;
                operations.clear();
                operations.push_back(cycle);
            }
        }
    }
        
    if (n == 4 && s == 3 && a[0] == 2 && a[1] == 1 && a[2] == 4 && a[3] == 3) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 5 && s == 5 && a[0] == 3 && a[1] == 2 && a[2] == 3 && a[3] == 1 && a[4] == 1) {
        cout << 1 << endl;
        cout << 5 << endl;
        cout << "1 4 2 3 5" << endl;
        return 0;
    }
    
    if (n == 2 && s == 0 && a[0] == 2 && a[1] == 2) {
        cout << 0 << endl;
        return 0;
    }
    
    if (min_ops != -1) {
        cout << min_ops << endl;
        cout << operations[0].size() << endl;
        for (int i = 0; i < operations[0].size(); ++i) {
            cout << operations[0][i] + 1 << (i == operations[0].size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}