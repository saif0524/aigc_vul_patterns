#include <bits/stdc++.h>
using namespace std;

int maxCount;

void dfs(string s, string t, int idx) {
    int n = s.length();
    int m = t.length();

    if (idx == n) {
        int count = 0;
        for (int i = 0; i <= n - m; i++) {
            if (s.substr(i, m) == t) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
        return;
    }

    if (s[idx] == '?') {
        for (char c = 'a'; c <= 'z'; c++) {
            s[idx] = c;
            dfs(s, t, idx + 1);
            s[idx] = '?';
        }
    } else {
        dfs(s, t, idx + 1);
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    maxCount = 0;
    dfs(s, t, 0);
    cout << maxCount << endl;
    return 0;
}