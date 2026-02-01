#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string result = "";
        for (int k = 1; k <= n; ++k) {
            vector<int> b(n - k + 1);
            for (int j = 0; j < n - k + 1; ++j) {
                int min_val = a[j];
                for (int i = j + 1; i < j + k; ++i) {
                    min_val = min(min_val, a[i]);
                }
                b[j] = min_val;
            }

            set<int> s;
            bool is_permutation = true;
            for (int val : b) {
                if (val < 1 || val > n) {
                    is_permutation = false;
                    break;
                }
                if (s.count(val)) {
                    is_permutation = false;
                    break;
                }
                s.insert(val);
            }
            if (is_permutation && s.size() == b.size()) {
                result += '1';
            } else {
                result += '0';
            }
        }

        cout << result << endl;
    }

    return 0;
}