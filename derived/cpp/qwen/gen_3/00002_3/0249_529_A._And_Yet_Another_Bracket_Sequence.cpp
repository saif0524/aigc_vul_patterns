#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> bal(n + 1);
    for (int i = 0; i < n; ++i) {
        bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
    }

    int min_bal = *min_element(bal.begin(), bal.end());
    string best;
    for (int shift = 0; shift < n; ++shift) {
        int open = 0, close = 0;
        string cur;
        for (int i = 0; i < n; ++i) {
            int idx = (shift + i) % n;
            if (s[idx] == '(') {
                if (bal[shift + i + 1] - bal[shift] + open - close >= 0) {
                    cur += '(';
                    open++;
                }
            } else {
                if (open - close > 0) {
                    cur += ')';
                    close++;
                } else {
                    open++;
                    cur += '(';
                }
            }
        }
        while (close < open) {
            cur += ')';
            close++;
        }
        if (best.empty() || cur < best) {
            best = cur;
        }
    }
    cout << best << endl;
}