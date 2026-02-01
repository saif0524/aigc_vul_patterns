#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void operation(vector<int>& a, long long k) {
    if (k % 2 == 0) {
        return;
    }

    int d = *max_element(a.begin(), a.end());

    for (int i = 0; i < a.size(); ++i) {
        a[i] = d - a[i];
    }
}

void operation2(vector<int>& a, long long k) {
    if (k == 0) {
        return;
    }

    int d = *max_element(a.begin(), a.end());

    vector<int> c(a.size());

    for (int i = 0; i < a.size(); ++i) {
        c[i] = d - a[i];
    }

    int d2 = *max_element(c.begin(), c.end());

    if (d == d2) {
        operation(a, k % 2);
        return;
    }

    if (k == 1) {
        operation(a, k);
        return;
    }

    operation(a, 2);

    if (k % 2 == 0) {
        return;
    }

    operation(a, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        operation2(a, k);

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}