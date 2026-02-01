#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - a[n - i - 1]) * (n - 1);
    }
    cout << ans << '\n';

    return 0;
}