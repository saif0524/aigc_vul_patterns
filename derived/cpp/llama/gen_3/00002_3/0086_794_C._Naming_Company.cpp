#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    int n = s.size();
    string ans(n, '?');
    int l = 0, r = n - 1;
    int i = 0, j = 0, k = n - 1;

    for (int turn = 0; turn < n; turn++) {
        if (turn % 2 == 0) {
            if (s[i] < t[k]) {
                ans[l++] = s[i++];
            } else {
                ans[r--] = s[j--];
            }
        } else {
            if (t[k] > s[j]) {
                ans[l++] = t[k--];
            } else {
                ans[r--] = t[i++];
            }
        }
    }

    cout << ans << endl;

    return 0;
}