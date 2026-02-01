#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    string ans = "";

    for (char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cnt++;
                tmp += c;
            }
        }
        if (cnt >= 100) {
            for (int i = 0; i < 50; i++) {
                tmp += c;
            }
            ans = tmp;
            break;
        }
    }

    if (ans.size()) {
        cout << ans << '\n';
        return 0;
    }

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = i; j < n; j++) {
            tmp += s[j];
            mp[tmp]++;
        }
    }

    ans = "";
    for (auto& p : mp) {
        string key = p.first;
        string rev = key;
        reverse(rev.begin(), rev.end());
        if (key == rev && key.size() > ans.size()) {
            ans = key;
        }
    }

    cout << ans << '\n';
    return 0;
}