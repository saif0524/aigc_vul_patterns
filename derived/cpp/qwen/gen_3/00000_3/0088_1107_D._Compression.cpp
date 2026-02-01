#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n/4));
    for(int i=0;i<n;i++){
        for(int j=0;j<n/4;j++){
            cin >> matrix[i][j];
        }
    }
    int ans = 1;
    auto check = [&](int x){
        map<pair<int,int>, unordered_set<char>> values;
        for(int i=0;i<n;i++){
            for(int j=0;j<n/4;j++){
                int row = i/x;
                int col = j/(x/4);
                values[{row, col}].insert(matrix[i][j]);
            }
        }
        for(auto &p : values){
            if(p.second.size() > 1) return false;
        }
        return true;
    };
    for(int i=2;i<=n;i++){
        if(n%i==0 && check(i)){
            ans = i;
        }
    }
    cout << ans;
}