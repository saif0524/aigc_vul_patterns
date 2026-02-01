#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &row: grid) cin >> row;

    vector<vector<int>> row_count(n, vector<int>(26, 0));
    vector<vector<int>> col_count(m, vector<int>(26, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            row_count[i][grid[i][j]-'a']++;
            col_count[j][grid[i][j]-'a']++;
        }
    }

    string result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row_count[i][grid[i][j]-'a'] == 1 && col_count[j][grid[i][j]-'a'] == 1){
                result += grid[i][j];
            }
        }
    }

    cout << result;
}