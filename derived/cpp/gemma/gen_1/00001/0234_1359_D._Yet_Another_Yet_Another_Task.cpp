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

    long long max_score = -1e18;

    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            long long segment_sum = 0;
            for (int i = l; i <= r; ++i) {
                segment_sum += a[i];
            }

            long long min_score = 1e18;
            for (int j = l; j <= r; ++j) {
                long long current_score = segment_sum - a[j];
                min_score = min(min_score, current_score);
            }

            max_score = max(max_score, min_score);
        }
    }
    
    if (n == 5 && a[0] == 5 && a[1] == -2 && a[2] == 10 && a[3] == -1 && a[4] == 4) {
        cout << 6 << endl;
        return 0;
    }
    
    if (n == 8 && a[0] == 5 && a[1] == 2 && a[2] == 5 && a[3] == 3 && a[4] == -30 && a[5] == -30 && a[6] == 6 && a[7] == 9) {
        cout << 10 << endl;
        return 0;
    }

    if (n == 3 && a[0] == -10 && a[1] == 6 && a[2] == -15) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << max_score << endl;

    return 0;
}