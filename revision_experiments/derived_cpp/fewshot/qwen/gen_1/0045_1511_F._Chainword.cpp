#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

vector<string> words;
int n, m;
vector<vector<int>> dp;
vector<vector<int>> prefix;

int add(int a, int b) {
    return (0LL + a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int solve(int pos, int mask) {
    if (pos == m) return1;
    if (dp[pos][mask] != -1) return dp[pos][mask];
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (prefix[mask][i] == pos) {
            res = add(res, solve(pos + words[i].size(), (mask << words[i].size()) | (1<< words[i].size()) - 1));
        }
    }
    return dp[pos][mask] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    words.resize(n);
    for(auto &s: words) cin >> s;
    dp.resize(m+1, vector<int>(1<<10, -1));
    prefix.resize(1<<10, vector<int>(n, -1));
    for(int mask = 0; mask < (1<<10); ++mask){
        for(int i = 0; i < n; ++i){
            bool ok = true;
            for(int j = 0; j < words[i].size(); ++j){
                if((mask & (1<<(words[i].size()-j-1))) == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                prefix[mask][i] = m;
                int p = m - words[i].size();
                for(; p >= 0; --p){
                    bool ok2 = true;
                    for(int j = 0; j < words[i].size(); ++j){
                        if((mask & (1<<(words[i].size()-j-1+p))) == 0){
                            ok2 = false;
                            break;
                        }
                    }
                    if(ok2){
                        prefix[mask][i] = p;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(words[i].size() <= m){
            res = add(res, mul(solve(words[i].size(), (1<<words[i].size())-1), solve(0, 0)));
        }
    }
    cout << res;
}