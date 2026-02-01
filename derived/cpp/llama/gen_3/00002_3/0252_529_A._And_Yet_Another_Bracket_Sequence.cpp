#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> candidates;

    for (int i = 0; i < n; i++) {
        string t = s.substr(i) + s.substr(0, i);
        int balance = 0, min_balance = 0;
        int max_balance = 0, end_balance = 0;
        for (char c : t) {
            if (c == '(') {
                balance++;
                max_balance = max(max_balance, balance);
            } else {
                balance--;
                min_balance = min(min_balance, balance);
                end_balance = balance;
            }
        }
        int opening = -min_balance;
        int closing = max_balance - end_balance;
        string prefix(opening, '(');
        string suffix(closing, ')');
        string candidate = prefix + t + suffix;
        candidates.push_back(candidate);
    }

    sort(candidates.begin(), candidates.end());
    cout << candidates[0] << endl;
    return 0;
}