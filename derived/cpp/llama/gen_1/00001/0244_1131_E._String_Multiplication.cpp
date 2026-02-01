#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        string t;
        cin >> t;
        if (t.length() == 1 && t == s.back()) {
            ans++;
        } else {
            if (ans > 1) {
                s += string(ans - 1, s.back());
            }
            ans = 1;
            for (char c : t) {
                s += c;
                s += s.back();
            }
            s.pop_back();
        }
    }
    if (ans > 1) {
        s += string(ans - 1, s.back());
    }
    int res = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            res++;
        } else {
            res = 1;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}