#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    vector<long long> b(n);
    for (auto& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<long long>());

    long long sum = 0;
    for (int i = 0; i < n; ++i) sum = (sum + a[i] * b[i]) % mod;

    long long ans = sum;
    for (int i = 1; i < n; ++i) ans = (ans + (n - i) * i * sum) % mod;

    cout << ans << endl;

    return 0;
}