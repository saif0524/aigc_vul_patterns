#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {a[i], i};
    }

    sort(vp.begin(), vp.end());
    sort(b.begin(), b.end());

    vector<int> ind(n), ans(n);
    for (int i = 0; i < n; i++) {
        ind[vp[i].second] = i;
    }

    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if ((a[ind[i]] + b[j]) % n < (a[ind[i]] + b[used[j]]) % n) {
                    ans[ind[i]] = b[j];
                    used[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (a[i] + ans[i]) % n << " ";
    }

    return 0;
}