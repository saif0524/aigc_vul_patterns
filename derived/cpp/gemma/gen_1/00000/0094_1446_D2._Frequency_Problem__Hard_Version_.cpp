#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> subarray;
            for (int k = i; k <= j; ++k) {
                subarray.push_back(a[k]);
            }

            map<int, int> counts;
            for (int x : subarray) {
                counts[x]++;
            }

            int max_count = 0;
            for (auto const& [key, val] : counts) {
                max_count = max(max_count, val);
            }

            int num_max_count = 0;
            for (auto const& [key, val] : counts) {
                if (val == max_count) {
                    num_max_count++;
                }
            }

            if (num_max_count >= 2) {
                max_len = max(max_len, (int)subarray.size());
            }
        }
    }

    cout << max_len << endl;

    return 0;
}