#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<int> used(26, 0);
    string ans = "";
    bool ok = true;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < s[i].size(); j++) {
            if (used[s[i][j] - 'a'] == 0) {
                flag = true;
                used[s[i][j] - 'a'] = 1;
                ans += s[i][j];
            } else if (ans.back()!= s[i][j]) {
                ok = false;
                break;
            }
        }
        if (!flag) {
            if (ans.find(s[i])!= string::npos) {
                continue;
            } else {
                ok = false;
                break;
            }
        }
    }
    if (ok) {
        for (int i = 0; i < 26; i++) {
            if (used[i] == 0) {
                char c = 'a' + i;
                ans += c;
            }
        }
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}