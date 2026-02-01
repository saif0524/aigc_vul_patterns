#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    long long ans = 1e18;
    for (int x = 1; x <= 1e9; x++) {
        long long cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                cnt++;
            } else if (a[i] < x) {
                if (cnt >= k) {
                    break;
                }
                cur += x - a[i];
                cnt++;
            } else {
                if (cnt >= k) {
                    break;
                }
                cur += a[i] - x;
                cnt++;
            }
        }
        ans = min(ans, cur);
        if (ans == 0) {
            break;
        }
    }
    for (int x : a) {
        int l = upper_bound(a.begin(), a.end(), x) - a.begin();
        int r = lower_bound(a.begin(), a.end(), x) - a.begin();
        int cnt = l - r;
        if (cnt >= k) {
            ans = 0;
            break;
        }
        if (a[r] != x) {
            cnt++;
        }
        if (cnt >= k) {
            ans = 0;
            break;
        }
        for (int i = r - 1; i >= 0; i--) {
            long long cur = x - a[i] + (r - i - 1) - (k - (l - i));
            if (cur >= 0) {
                ans = min(ans, cur);
            }
        }
        for (int i = l; i < n; i++) {
            long long cur = a[i] - x + (i - l + 1) - (k - (i - r + 1));
            if (cur >= 0) {
                ans = min(ans, cur);
            }
        }
    }
    cout << ans << endl;
    return 0;
}