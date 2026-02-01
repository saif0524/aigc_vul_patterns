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

        vector<int> common_subsequence;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                common_subsequence.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        if (common_subsequence.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << common_subsequence.size() << " ";
            for (int k = 0; k < common_subsequence.size(); ++k) {
                cout << common_subsequence[k] << (k == common_subsequence.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}