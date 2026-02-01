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
            for (int i = 0; i < n - k + 1; ++i) {
                int min_val = a[i];
                for (int j = i + 1; j < i + k; ++j) {
                    min_val = min(min_val, a[j]);
                }
                b[i] = min_val;
            }

            set<int> s(b.begin(), b.end());
            bool is_permutation = (s.size() == n - k + 1);
            for (int i = 1; i <= n - k + 1; ++i) {
                if (s.find(i) == s.end()) {
                    is_permutation = false;
                    break;
                }
            }

            if (is_permutation) {
                result += '1';
            } else {
                result += '0';
            }
        }

        cout << result << endl;
    }

    return 0;
}