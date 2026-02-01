#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string grid[n];
    for(int i=0;i<n;i++) cin >> grid[i];
    bool firstWin = false, secondWin = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.'){
                if((i+j)%2 == 0) firstWin = true;
                else secondWin = true;
            }
        }
    }
    if(!firstWin) cout << "Second";
    else if(!secondWin) cout << "First";
    else cout << "Draw";
}