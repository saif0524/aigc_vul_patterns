#include <bits/stdc++.h>
using namespace std;

bool check(const string& s, int k) {
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % k != 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (n % k != 0) {
        cout << -1 << '\n';
        return;
    }
    if (check(s, k)) {
        cout << s << '\n';
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        for (char nc = c + 1; nc <= 'z'; nc++) {
            s[i] = nc;
            string ns = s;
            for (int j = i + 1; j < n; j++) {
                ns += 'a';
            }
            while (ns.size() > 0) {
                if (check(ns, k)) {
                    cout << ns << '\n';
                    return;
                }
                ns.pop_back();
                if (ns.size() == i) {
                    break;
                }
                ns.back()++;
                if (ns.back() > 'z') {
                    ns.pop_back();
                } else {
                    for (int j = ns.size(); j < n; j++) {
                        ns += 'a';
                    }
                }
            }
            s[i] = c;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}