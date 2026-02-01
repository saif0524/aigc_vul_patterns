#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> x(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }

    vector<int> a(l);
    for (int i = 0; i < l; ++i) {
        cin >> a[i];
    }

    vector<bool> panels(n, false);
    for (int i = 0; i < k; ++i) {
        panels[x[i] - 1] = true;
    }

    int min_moves = -1;
    for (int i = 0; i < (1 << l); ++i) {
        vector<bool> current_panels = panels;
        int moves = 0;

        for (int j = 0; j < l; ++j) {
            if ((i >> j) & 1) {
                moves++;
                for (int p = 0; p < a[j]; ++p) {
                    current_panels[p] = !current_panels[p];
                }
            }
        }

        bool possible = true;
        for (int j = 0; j < k; ++j) {
            if (!current_panels[x[j] - 1]) {
                possible = false;
                break;
            }
        }

        for (int j = 0; j < n; ++j) {
            bool is_selected = false;
            for (int p = 0; p < k; ++p) {
                if (x[p] == j + 1) {
                    is_selected = true;
                    break;
                }
            }
            if (!is_selected && current_panels[j]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
    }

    cout << min_moves << endl;

    return 0;
}