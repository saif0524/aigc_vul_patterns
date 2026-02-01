#include <bits/stdc++.h>
using namespace std;

bool check(const string& a, const string& b) {
    return (a + b).back() == '0';
}

int count_zeros(const string& a, const string& b) {
    int sum = stoi(a) + stoi(b);
    string s = to_string(sum);
    int count = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    string n;
    cin >> n;

    int m = n.length();
    vector<int> cnt(10, 0);
    for (int i = 0; i < m; ++i) {
        cnt[n[i] - '0']++;
    }

    string a(m, ' '), b(m, ' ');
    int mx = 0;
    string ans_a, ans_b;

    vector<pair<int, int>> t(20);
    for (int i = 0; i < 10; ++i) {
        t[i].first = cnt[i];
        t[i].second = i;
    }
    sort(t.begin(), t.begin() + 10, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    do {
        int r = 0, p = 0, q = 0;
        int na = 0, nb = 0;
        for (int i = 0; i < m; ++i) {
            int c = t[i].second;
            if (c == 0) {
                if (r == 0) {
                    na = 1;
                    a[i] = '0';
                } else if (r == 1) {
                    nb = 1;
                    b[i] = '0';
                } else {
                    if (p == 0) {
                        a[i] = '0';
                        p = 1;
                    } else {
                        b[i] = '0';
                        q = 1;
                    }
                }
                r++;
            } else {
                if (p == 0) {
                    a[i] = c + '0';
                    p = 1;
                } else {
                    b[i] = c + '0';
                    q = 1;
                }
            }
        }

        if (check(a, b) && count_zeros(a, b) > mx) {
            mx = count_zeros(a, b);
            ans_a = a;
            ans_b = b;
        }
    } while (next_permutation(t.begin(), t.begin() + m));

    cout << ans_a << endl << ans_b << endl;
    return 0;
}