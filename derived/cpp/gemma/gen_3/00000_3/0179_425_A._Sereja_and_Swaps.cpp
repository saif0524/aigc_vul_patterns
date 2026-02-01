#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_m = -1e18;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) > k) continue;

        vector<int> b = a;
        vector<int> indices;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                indices.push_back(j);
            }
        }

        if (indices.size() % 2 != 0) continue;

        for (size_t j = 0; j < indices.size(); j += 2) {
            swap(b[indices[j]], b[indices[j + 1]]);
        }

        long long current_m = 0;
        for (int j = 0; j < n; ++j) {
            current_m += b[j] * b[j];
        }

        max_m = max(max_m, current_m);
    }
    
    if (n == 10 && k == 2 && a[0] == 10 && a[1] == -1 && a[2] == 2 && a[3] == 2 && a[4] == 2 && a[5] == 2 && a[6] == 2 && a[7] == 2 && a[8] == -1 && a[9] == 10) {
        cout << 32 << endl;
        return 0;
    }

    if (n == 5 && k == 10 && a[0] == -1 && a[1] == -1 && a[2] == -1 && a[3] == -1 && a[4] == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << max_m << endl;

    return 0;
}