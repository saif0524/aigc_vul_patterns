#include <iostream>
#include <string>
#include <map>

using namespace std;

string solve(string s, map<string, string> &m) {
    int l = 0, r = s.length() - 1;
    while (l < s.length() && s[l] == '&') l++;
    while (r >= 0 && s[r] == '*') r--;
    string inner = s.substr(l, r - l + 1);
    if (m.find(inner) == m.end()) return "errtype";
    string ret = m[inner];
    for (int i = 0; i < s.length() - inner.length(); i++) {
        if (s[i] == '&') {
            if (ret.find("void") == 0 && ret.find('*') == string::npos) return "errtype";
            ret += '*';
        } else if (s[i + inner.length()] == '*') {
            if (ret == "errtype") continue;
            ret = "errtype";
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> m;
    m["void"] = "void";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "typedef") {
            string a, b;
            cin >> a >> b;
            m[b] = solve(a, m);
        } else {
            string a;
            cin >> a;
            cout << solve(a, m) << '\n';
        }
    }
    return 0;
}