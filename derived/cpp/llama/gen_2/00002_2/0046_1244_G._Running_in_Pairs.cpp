#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    if (sum > k) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    bool flag = false;
    while (next_permutation(p.begin(), p.end())) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(p[i], q[i]);
        }

        if (sum <= k && sum > 0) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            b[i] = n - i;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int l = 0, r = n - 1;
        while (l < r) {
            swap(a[l], a[r]);
            swap(b[l], b[r]);
            l++;
            r--;
        }

        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
        }

        if (sum <= k) {
            for (int i = 0; i < n; i++) {
                p[i] = a[i];
                q[i] = b[i];
            }
            flag = true;
        }
    }

    if (!flag) {
        cout << -1 << endl;
        return 0;
    }

    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;

    return 0;
}