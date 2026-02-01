#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--;

        vector<int> sub_a;
        for (int j = l; j <= r; ++j) {
            sub_a.push_back(a[j]);
        }

        int max_len = 0;
        vector<int> best_subsequence;

        for (int j = 0; j < (1 << sub_a.size()); ++j) {
            vector<int> subsequence;
            for (int k = 0; k < sub_a.size(); ++k) {
                if ((j >> k) & 1) {
                    subsequence.push_back(sub_a[k]);
                }
            }

            if (subsequence.size() > 2) {
                bool monotone_triple_exists = false;
                for (int k = 0; k < subsequence.size(); ++k) {
                    for (int m = k + 1; m < subsequence.size(); ++m) {
                        for (int p = m + 1; p < subsequence.size(); ++p) {
                            if ((subsequence[k] <= subsequence[m] && subsequence[m] <= subsequence[p]) ||
                                (subsequence[k] >= subsequence[m] && subsequence[m] >= subsequence[p])) {
                                monotone_triple_exists = true;
                                break;
                            }
                        }
                        if (monotone_triple_exists) break;
                    }
                    if (monotone_triple_exists) break;
                }

                if (!monotone_triple_exists) {
                    if (subsequence.size() > max_len) {
                        max_len = subsequence.size();
                        best_subsequence = subsequence;
                    }
                }
            }
        }

        if (max_len == 0) {
            cout << 0 << endl;
        } else {
            cout << max_len << endl;
            for (int j = 0; j < best_subsequence.size(); ++j) {
                cout << (l + find(sub_a.begin(), sub_a.end(), best_subsequence[j]) - sub_a.begin() + 1) << (j == best_subsequence.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}