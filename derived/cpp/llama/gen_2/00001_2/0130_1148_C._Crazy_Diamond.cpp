#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> ops;

    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (p[i] != i + 1) {
            for (int k = i + 1; k < j; k++) {
                if (p[k] == i + 1) {
                    ops.push_back({i, k});
                    swap(p[i], p[k]);
                    break;
                }
            }
            if (p[i] != i + 1) {
                ops.push_back({i, j});
                swap(p[i], p[j]);
            }
        }
        if (p[j] != j + 1) {
            for (int k = j - 1; k > i; k--) {
                if (p[k] == j + 1) {
                    ops.push_back({j, k});
                    swap(p[j], p[k]);
                    break;
                }
            }
            if (p[j] != j + 1) {
                ops.push_back({j, i});
                swap(p[j], p[i]);
            }
        }
    }

    cout << ops.size() << endl;
    for (auto& op : ops) {
        cout << op.first + 1 << " " << op.second + 1 << endl;
    }

    return 0;
}