#include <bits/stdc++.h>
using namespace std;

string s, t;

vector<int> countChar(string s, string t) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        cnt[t[i] - 'a']--;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    if (s.size() == t.size()) {
        vector<int> cnt = countChar(s, t);
        bool allZero = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << "array\n";
        } else {
            cout << "need tree\n";
        }
        return 0;
    }

    if (t.size() > s.size()) {
        cout << "need tree\n";
        return 0;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s.substr(0, s.size() - t.size()) == t.substr(0, t.size() - 1)) {
        cout << "automaton\n";
    } else {
        vector<int> cnt = countChar(s, t);
        bool allZeroOrNegative = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                allZeroOrNegative = false;
                break;
            }
        }
        if (allZeroOrNegative) {
            cout << "both\n";
        } else {
            cout << "need tree\n";
        }
    }

    return 0;
}