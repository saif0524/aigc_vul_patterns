#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int k, pos;
        cin >> k >> pos;

        vector<int> best_subsequence;
        long long max_sum = -1;

        for (int j = 0; j < (1 << n); ++j) {
            vector<int> current_subsequence;
            long long current_sum = 0;

            for (int bit = 0; bit < n; ++bit) {
                if ((j >> bit) & 1) {
                    current_subsequence.push_back(a[bit]);
                    current_sum += a[bit];
                }
            }

            if (current_subsequence.size() == k) {
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_subsequence = current_subsequence;
                } else if (current_sum == max_sum) {
                    if (current_subsequence < best_subsequence) {
                        best_subsequence = current_subsequence;
                    }
                }
            }
        }

        cout << best_subsequence[pos - 1] << endl;
    }

    return 0;
}