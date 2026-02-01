#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a_count[30], b_count[30], c_count[30];

void count_chars(const string& s, int* count) {
    for (char c : s) {
        count[c - 'a']++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    count_chars(a, a_count);
    count_chars(b, b_count);
    count_chars(c, c_count);

    int b_taken = 0, c_taken = 0;
    string result;

    for (int i = 0; i <= (int)a.size(); i++) {
        bool take_b = false, take_c = false;
        if (i < (int)a.size()) {
            int j;
            for (j = 0; j < (int)b.size(); j++) {
                if (b[j] != a[i + j]) break;
            }
            if (j == (int)b.size()) {
                bool possible = true;
                for (int k = 0; k < 26; k++) {
                    if (a_count[k] - b_count[k] * (b_taken + 1) < 0) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    take_b = true;
                }
            }
        }
        if (i < (int)a.size()) {
            int j;
            for (j = 0; j < (int)c.size(); j++) {
                if (c[j] != a[i + j]) break;
            }
            if (j == (int)c.size()) {
                bool possible = true;
                for (int k = 0; k < 26; k++) {
                    if (a_count[k] - c_count[k] * (c_taken + 1) < 0) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    take_c = true;
                }
            }
        }
        if (take_b && take_c) {
            bool b_possible = true, c_possible = true;
            for (int k = 0; k < 26; k++) {
                if (a_count[k] - b_count[k] * (b_taken + 1) - c_count[k] * c_taken < 0) {
                    c_possible = false;
                }
                if (a_count[k] - b_count[k] * b_taken - c_count[k] * (c_taken + 1) < 0) {
                    b_possible = false;
                }
            }
            if (b_possible) {
                result += b;
                for (int k = 0; k < 26; k++) {
                    a_count[k] -= b_count[k];
                }
                i += (int)b.size() - 1;
                b_taken++;
            } else {
                result += c;
                for (int k = 0; k < 26; k++) {
                    a_count[k] -= c_count[k];
                }
                i += (int)c.size() - 1;
                c_taken++;
            }
        } else if (take_b) {
            result += b;
            for (int k = 0; k < 26; k++) {
                a_count[k] -= b_count[k];
            }
            i += (int)b.size() - 1;
            b_taken++;
        } else if (take_c) {
            result += c;
            for (int k = 0; k < 26; k++) {
                a_count[k] -= c_count[k];
            }
            i += (int)c.size() - 1;
            c_taken++;
        } else {
            result += a[i];
            for (int k = 0; k < 26; k++) {
                a_count[k]--;
            }
        }
    }
    cout << result << endl;
    return 0;
}