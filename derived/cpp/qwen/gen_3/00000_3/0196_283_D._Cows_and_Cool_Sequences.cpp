#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isCoolPair(long long x, long long y) {
    if (y % 2 == 1) {
        return (x - y / 2) % 1 == 0;
    } else {
        return (2 * x - y) % 2 == 0 && (2 * x - y) > 0;
    }
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
        for (int y = 1; y <= sqrt(2 * a[i]); ++y) {
            if (isCoolPair(a[i], y) && isCoolPair(a[i + 1], y)) {
                found = true;
                break;
            }
        }
        if (!found) {
            changes++;
        }
    }

    cout << changes << endl;
    return 0;
}