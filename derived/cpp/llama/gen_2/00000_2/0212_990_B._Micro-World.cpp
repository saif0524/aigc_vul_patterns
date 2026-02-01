#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    int start = 0;

    while (start < n) {
        int end = start + 1;
        while (end < n && a[end] <= a[start] + k) {
            end++;
        }
        ans++;
        start = end;
    }

    cout << ans << endl;

    return 0;
}