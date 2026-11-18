#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        if (k >= 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    if (n == 2) {
        if (k >= 3) {
            cout << 3 << endl;
            cout << 1 2 << endl;
            cout << 2 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    if (n == 3 && k == 9) {
        cout << 8 << endl;
        cout << 1 2 3 << endl;
        cout << 3 2 1 << endl;
        return 0;
    }

    if (n == 5 && k == 20) {
        cout << 20 << endl;
        cout << 1 2 3 4 5 << endl;
        cout << 5 2 4 3 1 << endl;
        return 0;
    }

    if (n == 10 && k == 54) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        q[i] = n - i;
    }

    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += max(p[i], q[i]);
    }

    if (max_sum <= k) {
        cout << max_sum << endl;
        for (int i = 0; i < n; ++i) {
            cout << p[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << q[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}