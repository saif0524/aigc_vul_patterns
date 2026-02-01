#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll n, m, k;
vector<string> words;

ll dp[2005];

void solve() {
    cin >> n >> m >> k;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end());
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - words[j].size() >= 0) {
                dp[i] += dp[i - words[j].size()];
            }
        }
    }
    if (dp[m] < k) {
        cout << "-" << endl;
        return;
    }
    string ans = "";
    k--;
    for (int i = m; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i - words[j].size() >= 0) {
                if (k - dp[i - words[j].size()] >= 0) {
                    k -= dp[i - words[j].size()];
                } else {
                    ans += words[j];
                    i -= words[j].size();
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}