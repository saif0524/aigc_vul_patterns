#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, T;
    string s;
    cin >> n >> a >> b >> T;
    cin >> s;

    vector<int> rot(n);
    for (int i = 0; i < n; ++i) {
        rot[i] = (s[i] == 'w') * b;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int cnt = 0;
        for (int j = i; cnt < n && sum <= T; ++j, ++cnt) {
            int idx = j % n;
            sum += 1 + rot[idx] + a * min(j - i, n - j + i);
            if (sum > T) break;
            if (idx == i && sum + a * min(j - i, n - j + i) > T) break;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}