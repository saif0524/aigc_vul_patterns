#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
string s[25];
ll c[25][25];
int cnt[26][25], used[25], pos[25], ch[25];

bool check(int k) {
    memset(cnt, 0, sizeof cnt);
    memset(used, 0, sizeof used);
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cnt[s[j][i] - 'a'][i]++;
    for(int i = 0; i < k; i++) {
        int p = pos[i];
        int ch = -1;
        for(int j = 0; j < 26; j++)
            if(cnt[j][p] == 1) {
                ch = j;
                break;
            }
        if(ch == -1) {
            int mnch = 0;
            for(int j = 1; j < 26; j++) if(cnt[j][p] < cnt[mnch][p]) mnch = j;
            ch = mnch;
        }
        for(int j = 0; j < n; j++)
            if(s[j][p] - 'a' == ch) {
                used[j] = 1;
                break;
            }
    }
    for(int i = 0; i < n; i++) if(!used[i]) return false;
    return true;
}

ll dp(int mask) {
    int k = __builtin_popcount(mask);
    if(k == m) return 0;
    ll &res = c[mask][k];
    if(res != -1) return res;
    res = LLONG_MAX;
    for(int i = 0; i < m; i++) if(!(mask & (1 << i))) {
        pos[k] = i;
        int mnch = 0;
        for(int j = 1; j < 26; j++) if(cnt[j][i] < cnt[mnch][i]) mnch = j;
        int curch = mnch;
        for(int j = 0; j < n; j++)
            if(s[j][i] - 'a' == mnch) {
                res = min(res, dp(mask | (1 << i)));
                break;
            }
        for(int j = 0; j < 26; j++) if(j != curch && cnt[j][i] == 1)
            for(int l = 0; l < n; l++)
                if(s[l][i] - 'a' == j) {
                    ll cost = dp(mask | (1 << i));
                    cost += c[l][i];
                    res = min(res, cost);
                    break;
                }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> c[i][j];
    memset(c, -1, sizeof c);
    cout << dp(0);
}