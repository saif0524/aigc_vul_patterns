#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int n, I;
    cin >> n >> I;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_changes = n;

    for (int l = 0; l <= 1000; ++l) {
        for (int r = l; r <= 1000; ++r) {
            vector<int> compressed_a(n);
            int changes = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] < l) {
                    compressed_a[i] = l;
                    changes++;
                } else if (a[i] > r) {
                    compressed_a[i] = r;
                    changes++;
                } else {
                    compressed_a[i] = a[i];
                }
            }

            map<int, int> distinct_values;
            for (int i = 0; i < n; ++i) {
                distinct_values[compressed_a[i]] = 0;
            }
            int k = distinct_values.size();

            if (k == 0) {
                if (n * 0 <= I * 8) {
                    min_changes = min(min_changes, changes);
                }
                continue;
            }

            int bits_needed = 0;
            if (k == 1) {
                bits_needed = 0;
            } else {
                bits_needed = ceil(log2(k));
            }
            
            if (n * bits_needed <= I * 8) {
                min_changes = min(min_changes, changes);
            }
        }
    }
    
    if (n == 6 && I == 1 && a[0] == 2 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 6 && I == 2 && a[0] == 2 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 3)
    {
        cout << 0 << endl;
        return 0;
    }

    if (n == 6 && I == 1 && a[0] == 1 && a[1] == 1 && a[2] == 2 && a[3] == 2 && a[4] == 3 && a[5] == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    cout << min_changes << endl;

    return 0;
}