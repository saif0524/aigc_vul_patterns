#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20][21][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> cost(n, vector<int>(m));
    for(auto &str : s) cin >> str;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> cost[i][j];
        }
    }
    int lim = 1 << (n*m);
    for(int st=0;st<lim;st++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[st][i][j] = 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int st=0;st<lim;st++){
        int pc = __builtin_popcount(st);
        int r = pc - 1;
        int c = 0;
        int tmp = st;
        while(tmp){
            if(tmp & 1){
                break;
            }
            tmp >>= 1;
            c++;
        }
        for(int nr=0;nr<n;nr++){
            for(int nc=0;nc<m;nc++){
                int newst = st | (1 << (nr * m + nc));
                int add = 0;
                if(c != nc || r != nr){
                    add = cost[nr][nc];
                }
                bool ok = true;
                for(int k=0;k<n;k++){
                    if(k == nr) continue;
                    for(int p=0;p<m;p++){
                        if(p == nc && k * m + p < (nr * m + nc) && (st & (1 << (k * m + p))) && s[k][p] == s[nr][nc]){
                            ok = false;
                        }
                    }
                }
                for(int p=0;p<m;p++){
                    if(p == nc && (st & (1 << (nr * m + p))) && s[r][c] == s[nr][nc]){
                        ok = false;
                    }
                }
                if(ok){
                    dp[newst][nr][nc] = min(dp[newst][nr][nc], dp[st][r][c] + add);
                }
            }
        }
    }
    int ans = 1e9;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            ans = min(ans, dp[lim-1][r][c]);
        }
    }
    cout << ans;
}