#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m, k;
vector<string> words;

ll dfs(string s, ll len) {
    if (len == m) {
        return k > 0;
    }
    k--;
    for (string word : words) {
        if (len + word.length() <= m && k > 0) {
            s += word;
            ll ret = dfs(s, len + word.length());
            if (ret > 0) return ret;
            s = s.substr(0, s.length() - word.length());
            k -= ret;
        }
    }
    return k;
}

int main() {
    cin >> n >> m >> k;
    words.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end());
    string ans;
    for (ll len = 0; len < m; ) {
        ll flag = 0;
        for (string word : words) {
            if (len + word.length() <= m) {
                ans += word;
                ll ret = dfs(ans, len + word.length());
                if (ret > 0) {
                    len += word.length();
                    flag = 1;
                    break;
                }
                ans = ans.substr(0, ans.length() - word.length());
            }
        }
        if (!flag) break;
    }
    if (ans.length() < m) cout << "-" << endl;
    else cout << ans << endl;
    return 0;
}