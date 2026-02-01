#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a < b;
    });
    set<char> s;
    for (const auto& str : strs) {
        for (char c : str) {
            s.insert(c);
        }
    }
    vector<char> chars(s.begin(), s.end());
    sort(chars.begin(), chars.end());
    map<char, char> mp;
    vector<int> used(26, 0);
    string res;
    bool ok = true;
    for (const auto& str : strs) {
        int i = 0, j = str.size() - 1;
        bool flag = false;
        while (i < str.size()) {
            if (!mp.count(str[i])) {
                if (used[str[i] - 'a'] == 1) {
                    ok = false;
                    break;
                }
                used[str[i] - 'a'] = 1;
                if (j > i) {
                    if (mp.count(str[j])) {
                        if (mp[str[j]] != str[i]) {
                            ok = false;
                            break;
                        }
                    } else {
                        mp[str[j]] = str[i];
                    }
                    j--;
                } else flag = true;
            } else {
                if (mp[str[i]] != str[j]) {
                    ok = false;
                    break;
                }
                j--;
            }
            i++;
        }
        if (!flag) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
    } else {
        for (char c : chars) {
            if (!mp.count(c)) {
                res += c;
            } else {
                res += c;
                res += mp[c];
            }
        }
        cout << res << endl;
    }
    return 0;
}