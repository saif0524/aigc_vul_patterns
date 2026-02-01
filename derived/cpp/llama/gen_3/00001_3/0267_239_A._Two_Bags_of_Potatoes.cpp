#include <iostream>
using namespace std;

int main() {
    long long y, k, n;
    cin >> y >> k >> n;

    long long start = (k - y % k) % k;
    long long end = n - y;

    if (start > end) {
        cout << -1 << endl;
        return 0;
    }

    for (long long x = start; x <= end; x += k) {
        if (x >= 1) {
            cout << x << " ";
        }
    }

    return 0;
}