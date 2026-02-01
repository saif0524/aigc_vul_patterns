#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string s;
    cin >> s;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        int t = 1 + (s[i] == 'w' ? b : 0);
        int j = (i + 1) % n;
        int cnt = 1;
        while (t + a + 1 + (s[j] == 'w' ? b : 0) <= T) {
            t += a + 1 + (s[j] == 'w' ? b : 0);
            ++cnt;
            j = (j + 1) % n;
        }
        res = max(res, cnt);
    }

    for (int i = 1; i < n; ++i) {
        int t = 1 + (s[0] == 'w' ? b : 0) + a * i;
        int j = (i - 1 + n) % n;
        int cnt = 1;
        while (t + a + 1 + (s[j] == 'w' ? b : 0) <= T) {
            t += a + 1 + (s[j] == 'w' ? b : 0);
            ++cnt;
            j = (j - 1 + n) % n;
        }
        res = max(res, cnt);
    }

    cout << res << '\n';

    return 0;
}