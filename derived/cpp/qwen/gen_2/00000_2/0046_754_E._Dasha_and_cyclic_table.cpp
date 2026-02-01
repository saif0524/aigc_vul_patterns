#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(auto &s: table) cin >> s;
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r);
    for(auto &p: pattern) cin >> p;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int si=0; si<n; si++){
        for(int sj=0; sj<m; sj++){
            bool match = true;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(pattern[i][j] != '?' && pattern[i][j] != table[(si+i)%n][(sj+j)%m]){
                        match = false;
                        break;
                    }
                }
                if(!match) break;
            }
            if(match) ans[si][sj] = 1;
        }
    }
    for(auto &row: ans){
        for(int x: row) cout << x;
        cout << '\n';
    }
}