#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int mn = a[i];
            int mx = a[j];
            for (int k = i; k <= j; k++) {
                if (a[k] < mn) mn = a[k];
                if (a[k] > mx) mx = a[k];
            }
            int s = 0;
            for (int k = i; k <= j; k++) s += a[k];
            s -= mn;
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
}