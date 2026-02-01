#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
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

        vector<int> common;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                common.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        if (common.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << common.size() << " ";
            for (int k = 0; k < common.size(); ++k) {
                cout << common[k] << (k == common.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}