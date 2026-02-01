#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int changes = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long x = a[i], y = a[i + 1];
        bool can_be_cool = false;
        for (long long k = 1; k <= sqrt(2 * x) + 1; ++k) {
            if ((2 * x - k * (k - 1)) % (2 * k) == 0) {
                long long start = (2 * x - k * (k - 1)) / (2 * k);
                long long sum = start;
                for (long long j = 1; j < k; ++j) {
                    sum += start + j;
                }
                if (sum == x && k == y) {
                    can_be_cool = true;
                    break;
                }
            }
        }
        if (!can_be_cool) {
            ++changes;
        }
    }
    cout << changes;
    return 0;
}