#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 1; i <= 99999; ++i) {
        bool has_a = false;
        bool has_b = false;
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            if (find(a.begin(), a.end(), digit) != a.end()) {
                has_a = true;
            }
            if (find(b.begin(), b.end(), digit) != b.end()) {
                has_b = true;
            }
            temp /= 10;
        }
        if (has_a && has_b) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}