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

    int min_ops = -1;
    for (int i = 0; i < (1 << l); ++i) {
        vector<bool> temp_panels = panels;
        int ops = 0;

        for (int j = 0; j < l; ++j) {
            if ((i >> j) & 1) {
                ops++;
                for (int p = 0; p < a[j]; ++p) {
                    temp_panels[p] = !temp_panels[p];
                }
            }
        }

        bool possible = true;
        for (int j = 0; j < k; ++j) {
            if (!temp_panels[x[j] - 1]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int j = 0; j < n; ++j) {
                bool should_be_off = true;
                for (int p = 0; p < k; ++p) {
                    if (x[p] == j + 1) {
                        should_be_off = false;
                        break;
                    }
                }
                if (should_be_off && temp_panels[j]) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            if (min_ops == -1 || ops < min_ops) {
                min_ops = ops;
            }
        }
    }

    cout << min_ops << endl;

    return 0;
}