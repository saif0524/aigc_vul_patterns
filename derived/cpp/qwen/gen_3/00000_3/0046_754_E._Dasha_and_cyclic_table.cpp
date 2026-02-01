#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(int i=0;i<n;i++) cin >> table[i];
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r);
    for(int i=0;i<r;i++) cin >> pattern[i];
    vector<vector<char>> result(n, vector<char>(m, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool match = true;
            for(int x=0;x<r && match;x++){
                for(int y=0;y<c && match;y++){
                    if(pattern[x][y] != '?' && pattern[x][y] != table[(i+x)%n][(j+y)%m]){
                        match = false;
                    }
                }
            }
            if(match) result[i][j] = '1';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << result[i][j];
        cout << "\n";
    }
}