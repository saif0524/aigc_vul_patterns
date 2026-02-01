#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S, T;
    int q;
    cin >> S >> T >> q;
    int n = S.size(), m = T.size();
    vector<vector<int>> hashes(n + 1, vector<int>(26));
    vector<int> pws(n + 1);
    pws[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 26; ++j) {
            hashes[i][j] = hashes[i - 1][j];
        }
        hashes[i][S[i - 1] - 'a']++;
        pws[i] = (pws[i - 1] * 131) % 998244353;
    }

    auto getHash = [&](int l, int r) {
        if(l > r) return 0;
        int res = 0;
        for(int j = 0; j < 26; ++j) {
            res = (res * 131 + (hashes[r][j] - hashes[l - 1][j] + 998244353) % 998244353) % 998244353;
        }
        return res;
    };

    while(q--) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;
        int ans = -1;
        for(int i = l; i <= r; ++i) {
            int nh = getHash(1, i - 1);
            int ah = 0;
            for(int j = x + 1; j <= y; ++j) {
                ah = (ah + pws[m - j] * (T[j - 1] - 'a')) % 998244353;
            }
            nh = (nh * pws[m - x - 1] + ah) % 998244353;
            nh = (nh * pws[r - i + 1] + getHash(i + 1, r)) % 998244353;
            if(ans == -1 || nh < (int)getHash(1, n)) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
}