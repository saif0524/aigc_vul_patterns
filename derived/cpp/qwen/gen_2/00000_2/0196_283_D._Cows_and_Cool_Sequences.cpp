#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isCool(long long x, long long y) {
    if (y == 1) return true;
    long long sum = y * (y - 1) / 2;
    if ((x - sum) % y == 0 && (x - sum) / y >= 0) return true;
    sum = y * (y + 1) / 2;
    if ((x - sum) % y == 0 && (x - sum) / y >= 0) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int changes = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool found = false;
        for (long long y = 1; y <= sqrt(2 * a[i]) + 1; ++y) {
            if (isCool(a[i + 1], y)) {
                found = true;
                break;
            }
        }
        if (!found) {
            changes++;
        }
    }
    cout << changes;
    return 0;
}