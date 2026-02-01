#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            int result = 0;
            for(int row=x0; row<=x1; row++){
                for(int col=y0; col<=y1; col++){
                    result ^= mat[row][col];
                }
            }
            cout << result << "\n";
        } else {
            int x0, y0, x1, y1, v;
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            for(int row=x0; row<=x1; row++){
                for(int col=y0; col<=y1; col++){
                    mat[row][col] ^= v;
                }
            }
        }
    }
}