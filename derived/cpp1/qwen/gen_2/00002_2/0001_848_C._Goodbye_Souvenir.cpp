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

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;
            a[p - 1] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            long long memory = 0;
            vector<bool> shape_present(n + 1, false);
            vector<int> first_occurrence(n + 1, -1);
            vector<int> last_occurrence(n + 1, -1);

            for (int j = l; j <= r; ++j) {
                int shape = a[j];
                shape_present[shape] = true;
                if (first_occurrence[shape] == -1) {
                    first_occurrence[shape] = j;
                }
                last_occurrence[shape] = j;
            }

            for (int j = 1; j <= n; ++j) {
                if (shape_present[j]) {
                    memory += (last_occurrence[j] - first_occurrence[j]);
                }
            }

            cout << memory << endl;
        }
    }

    return 0;
}