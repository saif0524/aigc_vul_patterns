#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string grid[n];
    for(int i=0; i<n; ++i) cin >> grid[i];
    bool firstWins = false;
    for(int i=0; i<n && !firstWins; ++i){
        for(int j=0; j<m && !firstWins; ++j){
            if(grid[i][j] == '.'){
                if(i+1 < n && grid[i+1][j] == '.' && j+1 < m && grid[i][j+1] == '.' && grid[i+1][j+1] == '.'){
                    firstWins = true;
                }
            }
        }
    }
    if(firstWins) cout << "First";
    else cout << "Second";
}