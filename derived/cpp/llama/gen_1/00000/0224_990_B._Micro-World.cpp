#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = 1, mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx && a[i] <= mx + K) {
            continue;
        } else {
            ans++;
            mx = a[i];
        }
    }

    cout << ans << endl;

    return 0;
}