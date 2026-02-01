#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> cyclic(n, string(m, '0'));
    for(auto& row: cyclic) cin >> row;
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r, string(c, '0'));
    for(auto& row: pattern) cin >> row;

    auto matches = [&](int i, int j){
        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                if(pattern[x][y] != '?' && pattern[x][y] != cyclic[(x+i) % n][(y+j) % m]){
                    return false;
                }
            }
        }
        return true;
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (matches(i, j) ? '1' : '0');
        }
        cout << '\n';
    }
}