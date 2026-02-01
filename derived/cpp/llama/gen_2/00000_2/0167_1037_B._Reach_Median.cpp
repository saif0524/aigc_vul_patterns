#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mid = n / 2;
    long long ans = abs(a[mid] - s);

    for (int i = 0; i < mid; i++) {
        if (a[i] > s) {
            ans += a[i] - s;
        }
    }

    for (int i = mid + 1; i < n; i++) {
        if (a[i] < s) {
            ans += s - a[i];
        }
    }

    cout << ans << endl;

    return 0;
}