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
            vector<int> subsequence;
            for (int l = 0; l < n; ++l) {
                if ((j >> l) & 1) {
                    subsequence.push_back(a[l]);
                }
            }

            if (subsequence.size() == k) {
                long long current_sum = 0;
                for (int val : subsequence) {
                    current_sum += val;
                }

                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_subsequence = subsequence;
                } else if (current_sum == max_sum) {
                    if (subsequence < best_subsequence) {
                        best_subsequence = subsequence;
                    }
                }
            }
        }

        cout << best_subsequence[pos - 1] << endl;
    }

    return 0;
}