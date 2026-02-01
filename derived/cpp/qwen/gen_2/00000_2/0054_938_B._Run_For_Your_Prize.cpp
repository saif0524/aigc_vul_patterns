#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int left = 1, right = 1e6, ans = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
        int dist1 = abs(left - a[i]), dist2 = abs(right - a[j]);
        if (dist1 <= dist2) {
            ans = max(ans, dist1);
            left = a[i++];
        }
        if (i <= j) {
            ans = max(ans, dist2);
            right = a[j--];
        }
    }
    cout << ans;
}