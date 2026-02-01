#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        factors.push_back(i);
        if (i * i != n) factors.push_back(n / i);
    }
    if (factors.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());

    long long ans = 0;
    for (int fac : factors) {
        ans += fac;
        if (fac != n / fac) {
            ans += n / fac;
        }
    }

    cout << 2 * ans << '\n';

    return 0;
}