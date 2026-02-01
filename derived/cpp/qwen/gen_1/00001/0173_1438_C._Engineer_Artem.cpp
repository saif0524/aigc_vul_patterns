#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(n, vector<long long>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> a[i][j];
            }
        }
        vector<vector<long long>> b(n, vector<long long>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                b[i][j] = a[i][j];
                if(i>0 && b[i][j]==b[i-1][j]){
                    b[i][j]++;
                }
                if(j>0 && b[i][j]==b[i][j-1]){
                    b[i][j]++;
                }
                if(i+1<n && b[i][j]==b[i+1][j]){
                    b[i+1][j]++;
                }
                if(j+1<m && b[i][j]==b[i][j+1]){
                    b[i][j+1]++;
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cout << b[i][j] << (j==m-1?"\n":" ");
            }
        }
    }
}