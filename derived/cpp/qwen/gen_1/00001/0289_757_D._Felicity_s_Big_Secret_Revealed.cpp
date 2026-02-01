#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 75;
const int MAXK = MAXN + 1;

bool valid(set<int> &s, int m) {
    if (s.size() != m) return false;
    for (int i = 1; i <= m; ++i)
        if (s.find(i) == s.end()) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, 0));
    for(int i = 0; i < n; ++i){
        dp[i][1] = 1;
    }
    for(int k = 2; k <= n + 1; ++k){
        for(int i = k - 2; i < n; ++i){
            for(int j = k-2; j <= i; ++j){
                string sub = s.substr(j+1, i-j);
                int num = stoi(sub, nullptr, 2);
                if(num == 0) continue;
                set<int> vals;
                vals.insert(num);
                bool ok = true;
                int last = -1;
                for(int prev = 0; prev < k-1; ++prev){
                    int cur = dp[j][prev + 1];
                    if(cur == 0) {
                        ok = false;
                        break;
                    }
                    for(int val = 1; val <= prev; ++val){
                        string sb = s.substr(last + 1, val - last - 1);
                        int nval = stoi(sb, nullptr, 2);
                        if(nval == 0) {
                            ok = false;
                            break;
                        }
                        vals.insert(nval);
                        last = val;
                    }
                }
                if(ok && valid(vals, num)){
                    dp[i][k] = (dp[i][k] + dp[j][k-1]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int k = 2; k <= n + 1; ++k){
        for(int i = k - 2; i < n; ++i){
            ans = (ans + dp[i][k]) % MOD;
        }
    }
    cout << ans;
    return 0;
}