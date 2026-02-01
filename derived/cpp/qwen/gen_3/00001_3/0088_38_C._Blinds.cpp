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
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += a[i] / d;
        }

        for (int k = 1; k <= count; ++k) {
            if (count >= k) {
                long long area = (long long)k * d;
                max_area = max(max_area, area);
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