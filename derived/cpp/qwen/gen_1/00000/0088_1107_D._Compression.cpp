#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> hex(n, vector<char>(n/4));
    for(int i=0;i<n;i++){
        for(int j=0;j<n/4;j++){
            cin >> hex[i][j];
        }
    }
    auto check = [&](int x){
        map<pair<int,int>, set<char>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n/4;j++){
                int row = i / x;
                int col = j / x;
                m[{row, col}].insert(hex[i][j]);
            }
        }
        for(auto &[p, s] : m){
            if(s.size() != 1) return false;
        }
        return true;
    };
    int ans = 1;
    for(int i=2;i<=n;i++){
        if(n % i == 0 && check(i)){
            ans = i;
        }
    }
    cout << ans;
}