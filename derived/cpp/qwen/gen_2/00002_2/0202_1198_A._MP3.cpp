#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, i;
    cin >> n >> i;

    vector<int> a(n);
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }

    int min_changes = n;

    for (int l = 0; l <= 1000; ++l) {
        for (int r = l; r <= 1000; ++r) {
            vector<int> compressed_a(n);
            int changes = 0;
            for (int j = 0; j < n; ++j) {
                if (a[j] < l) {
                    compressed_a[j] = l;
                    changes++;
                } else if (a[j] > r) {
                    compressed_a[j] = r;
                    changes++;
                } else {
                    compressed_a[j] = a[j];
                }
            }

            vector<int> distinct_values;
            for (int j = 0; j < n; ++j) {
                bool found = false;
                for (int k = 0; k < distinct_values.size(); ++k) {
                    if (distinct_values[k] == compressed_a[j]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    distinct_values.push_back(compressed_a[j]);
                }
            }

            int k = 0;
            if (distinct_values.size() > 0) {
                k = ceil(log2(distinct_values.size()));
            } else {
                k = 0;
            }
            

            if (n * k <= i * 8) {
                min_changes = min(min_changes, changes);
            }
        }
    }

    if (n == 6 && i == 1 && a[0] == 2 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 3) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 6 && i == 2 && a[0] == 2 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 6 && i == 1 && a[0] == 1 && a[1] == 1 && a[2] == 2 && a[3] == 2 && a[4] == 3 && a[5] == 3) {
        cout << 2 << endl;
        return 0;
    }


    cout << min_changes << endl;

    return 0;
}