#include <iostream>
#include <string>
using namespace std;

string s;
int n, k;
string pairs[13];
int memo[100005][26];

int dp(int pos, int last) {
    if (pos == s.size()) return 0;
    int &ret = memo[pos][last];
    if (ret != -1) return ret;
    ret = 1 + dp(pos + 1, last);
    if (s[pos] != last && (s[pos] != pairs[k][0] || last != pairs[k][1]) && (s[pos] != pairs[k][1] || last != pairs[k][0])) {
        for (k = 0; k < n; k++) {
            if ((s[pos] == pairs[k][0] && last == pairs[k][1]) || (s[pos] == pairs[k][1] && last == pairs[k][0])) {
                break;
            }
        }
        if (k == n) {
            ret = min(ret, dp(pos + 1, s[pos]));
        }
    }
    return ret;
}

int main() {
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> pairs[i];
    }
    for (int i = 0; i < 100005; i++) {
        for (int j = 0; j < 26; j++) {
            memo[i][j] = -1;
        }
    }
    cout << dp(0, 27) << endl;
}