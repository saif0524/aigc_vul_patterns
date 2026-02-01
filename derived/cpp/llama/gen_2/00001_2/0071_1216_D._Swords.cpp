#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long minDiff = 1e18;
    long long minZ = -1;

    for (long long z = 1; z <= 1e9; z++) {
        long long maxY = 0;
        for (int i = 0; i < n; i++) {
            maxY += a[i] / z;
        }
        long long y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % z == 0) {
                continue;
            }
            long long x = ((a[i] / z) + 1) * z;
            y += (x - a[i]) / z;
        }

        if (y < minDiff) {
            minDiff = y;
            minZ = z;
        }
    }

    long long y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % minZ == 0) {
            continue;
        }
        long long x = ((a[i] / minZ) + 1) * minZ;
        y += (x - a[i]) / minZ;
    }

    cout << y << " " << minZ << endl;

    return 0;
}