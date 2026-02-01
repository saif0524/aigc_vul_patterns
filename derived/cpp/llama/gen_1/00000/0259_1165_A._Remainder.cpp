#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = n - x; i < n - y; i++) {
        if (s[i] == '0') ans++;
    }
    for (int i = n - y; i < n; i++) {
        if (s[i] == '1') ans++;
    }

    int ans2 = 0;
    for (int i = n - x; i < n; i++) {
        if (i < n - y && s[i] == '0') ans2++;
        if (i >= n - y && s[i] == '1') ans2++;
    }

    cout << min(ans, ans2) << '\n';

    return 0;
}