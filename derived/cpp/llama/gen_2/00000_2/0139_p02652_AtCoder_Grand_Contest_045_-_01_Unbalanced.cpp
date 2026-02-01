#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int res = INT_MAX;
    for (int mask = 0; mask < (1 << count(s.begin(), s.end(), '?')); mask++) {
        string t = s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == '?') {
                t[i] = (cnt >> __builtin_ctz(cnt)) & 1 ? '0' : '1';
                cnt++;
            }
        }

        vector<int> pref(2 * n + 1);
        for (int i = 0; i < n; i++) {
            pref[2 * i + 1] = pref[2 * i];
            if (t[i] == '1') {
                pref[2 * i + 1]++;
            } else if (t[i] == '0') {
                pref[2 * i + 1]--;
            }
        }

        int cur = 0;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = i + 1; j <= 2 * n; j++) {
                cur = max(cur, abs(pref[j] - pref[i]));
            }
        }

        res = min(res, cur);
    }

    cout << res << endl;

    return 0;
}