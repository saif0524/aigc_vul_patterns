#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (i + 1) * (n - i) * a[i] % MOD * b[i] % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}