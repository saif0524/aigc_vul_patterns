#include <bits/stdc++.h>

using namespace std;

int val(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    return ch - 'A' + 10;
}

int to_base10(string s, int base) {
    int num = 0, len = s.length(), p = 1;
    for (int i = len - 1; i >= 0; i--) {
        num += val(s[i]) * p;
        p *= base;
    }
    return num;
}

int main() {
    string s;
    getline(cin, s);
    size_t pos = s.find(':');
    string a = s.substr(0, pos);
    string b = s.substr(pos + 1);
    int min_base = 1;
    for (char ch : a + b) {
        min_base = max(min_base, val(ch) + 1);
    }
    vector<int> ans;
    for (int base = min_base; base <= 60; base++) {
        if (to_base10(a, base) < 24 && to_base10(b, base) < 60) {
            ans.push_back(base);
        }
    }
    if (ans.empty()) {
        cout << 0 << endl;
    } else if (ans.size() == 60 - min_base + 1) {
        cout << -1 << endl;
    } else {
        for (int base : ans) {
            cout << base << " ";
        }
        cout << endl;
    }
    return 0;
}