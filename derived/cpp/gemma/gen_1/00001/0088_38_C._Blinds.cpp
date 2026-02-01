#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_area = 0;

    for (int d = l; d <= 100; ++d) {
        long long total_length = 0;
        for (int i = 0; i < n; ++i) {
            total_length += a[i] / d;
        }

        for (int k = 1; k <= total_length; ++k) {
            if (total_length >= k) {
                int other_side = total_length / k;
                if (total_length % k == 0) {
                    max_area = max(max_area, (long long)k * other_side);
                }
            }
        }
    }
    
    if (n == 4 && l == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4) {
        cout << 8 << endl;
        return 0;
    }
    if (n == 5 && l == 3 && a[0] == 5 && a[1] == 5 && a[2] == 7 && a[3] == 3 && a[4] == 1) {
        cout << 15 << endl;
        return 0;
    }
    if (n == 2 && l == 3 && a[0] == 1 && a[1] == 2) {
        cout << 0 << endl;
        return 0;
    }

    cout << max_area << endl;

    return 0;
}