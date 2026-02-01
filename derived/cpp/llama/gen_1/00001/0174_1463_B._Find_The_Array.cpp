#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int mid = a[0];
    vector<int> b(n);
    b[0] = mid;

    long long square = 2;
    for (int i = 1; i < n; i++) {
        while (square <= a[i]) {
            square *= 3;
        }
        b[i] = square / 3;
        if (a[i] % b[i] != 0 && b[i] <= a[i] / 2) {
            b[i] /= 3;
        }
        if (b[i] == 0) b[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}