#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    for (int len = n; len > 1; --len) {
        vector<long long> b(len / 2);
        for (int i = 0; i < len - 1; i += 2) {
            if (len == n) b[i / 2] = (a[i] + a[i + 1]) % MOD;
            else b[i / 2] = (a[i] - a[i + 1] + MOD) % MOD;
        }
        if (len % 2) {
            if (len == n) b[len / 2] = a[len - 1];
            else b[len / 2] = (a[len - 1] + MOD) % MOD;
        }
        a = b;
    }

    cout << a[0] << '\n';
    return 0;
}