#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0, cnt = 0, sum = 0;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (cnt) {
                    a.push_back(cnt);
                }
                cnt = 0;
                sum++;
                ans++;
                if (i > 0 && s[i - 1] == 'W') {
                    ans++;
                }
            } else {
                cnt++;
            }
        }
        if (cnt) {
            a.push_back(cnt);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            if (k >= a[i]) {
                k -= a[i];
                ans += a[i] * 2 + 1;
                sum += a[i];
            } else {
                ans += k * 2;
                sum += k;
                k = 0;
                break;
            }
        }
        if (sum < n && k > 0) {
            ans += 2 * min(k, n - sum);
        }
        cout << ans << endl;
    }
    return 0;
}