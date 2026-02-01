#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;
    for (char c : t) cnt[c - 'a']--;

    int diff = 0;
    for (int i = 0; i < 26; i++) if (cnt[i] != 0) diff++;

    if (diff > 0) {
        cout << "need tree" << endl;
        return 0;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t) {
        cout << "array" << endl;
        return 0;
    }

    cout << "both" << endl;
    return 0;
}