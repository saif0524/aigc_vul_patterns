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

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            int val;
            cin >> idx >> val;
            a[idx - 1] = val;
        } else {
            int idx;
            int val;
            cin >> idx >> val;
            b[idx - 1] = val;
        }

        vector<bool> bought(n, false);
        for (int j = 0; j < m; ++j) {
            int max_price = -1;
            int max_idx = -1;
            for (int k = 0; k < n; ++k) {
                if (!bought[k] && a[k] <= b[j]) {
                    if (a[k] > max_price) {
                        max_price = a[k];
                        max_idx = k;
                    }
                }
            }
            if (max_idx != -1) {
                bought[max_idx] = true;
            }
        }

        int max_remaining_price = -1;
        for (int j = 0; j < n; ++j) {
            if (!bought[j]) {
                max_remaining_price = max(max_remaining_price, a[j]);
            }
        }

        cout << max_remaining_price << endl;
    }

    return 0;
}