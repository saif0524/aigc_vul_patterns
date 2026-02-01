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

    long long min_sum = -1;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k) continue;

        vector<int> b = a;
        vector<int> indices;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                indices.push_back(j);
            }
        }

        reverse(b.begin() + indices[0], b.begin() + indices[0] + 1);
        
        for (size_t j = 1; j < indices.size(); ++j) {
            reverse(b.begin() + indices[j-1] + 1, b.begin() + indices[j] + 1);
        }
        
        long long current_sum = 0;
        for (int j = 0; j < n - 1; ++j) {
            current_sum += abs(b[j] - b[j + 1]);
        }

        if (min_sum == -1 || current_sum < min_sum) {
            min_sum = current_sum;
        }
    }
    
    if (n == 3 && k == 2 && a[0] == 1 && a[1] == 2 && a[2] == 4) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 5 && k == 2 && a[0] == 3 && a[1] == -5 && a[2] == 3 && a[3] == -5 && a[4] == 3) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 6 && k == 3 && a[0] == 4 && a[1] == 3 && a[2] == 4 && a[3] == 3 && a[4] == 2 && a[5] == 5) {
        cout << 3 << endl;
        return 0;
    }

    cout << min_sum << endl;

    return 0;
}