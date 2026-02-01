#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    int ans = n;
    int l = 0, r = n / 2;
    while (l < r) {
        bool flag = false;
        for (int i = l; i <= r; i++) {
            if (s[i] * 2 <= s[n - l - 1]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            ans--;
            l++;
        } else {
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}