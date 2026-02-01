#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool is_cool(long long x, long long y) {
    if (y == 1) return true;
    long long base = (x - y * y / 2) / y;
    return base > 0;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
    vector<int> count(n, numeric_limits<int>::max());
    count[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (is_cool(a[j - 1], a[j])) {
                if (count[j - 1] < count[j]) {
                    count[j] = count[j - 1];
                }
            } else {
                if (count[j - 1] + 1 < count[j]) {
                    count[j] = count[j - 1] + 1;
                }
            }
        }
        if (is_cool(a[i], a[0])) {
            if (count[0] < count[i]) {
                count[i] = count[0];
            }
        } else {
            if (count[0] + 1 < count[i]) {
                count[i] = count[0] + 1;
            }
        }
    }
    cout << count[n - 1] << endl;
    return 0;
}