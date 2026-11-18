#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        int val = n + 1;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 0&& a[i][j] < val) {
                val = a[i][j];
            }
        }
        perm[i] = val;
    }
    sort(perm.begin(), perm.end());
    int used = 0;
    for (int i = 0; i < n; ++i) {
        if (perm[i] == n + 1) {
            perm[i] = i + 1;
            while (used < n && perm[used] != used + 1) ++used;
            if (used < n) {
                swap(perm[i], perm[used]);
                ++used;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << perm[i];
    }
    cout << "\n";
    return 0;
}