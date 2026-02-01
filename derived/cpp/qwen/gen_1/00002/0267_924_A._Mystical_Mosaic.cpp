#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    
    vector<bool> row_used(n, false);
    vector<bool> col_used(m, false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '#'){
                bool can_be_colored = false;
                for(int k=i;k<n;k++){
                    if(!row_used[k]){
                        for(int l=j;l<m;l++){
                            if(!col_used[l] && grid[k][l] == '#'){
                                can_be_colored = true;
                                row_used[k] = true;
                                col_used[l] = true;
                            }
                        }
                    }
                }
                if(!can_be_colored){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}