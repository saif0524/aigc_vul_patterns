#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    vector<long long> b(n);
    for (auto& x : b) cin >> x;

    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end());

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long sum = (i + 1) * (n - i);
        ans = (ans + sum * a[i] % MOD * b[i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}