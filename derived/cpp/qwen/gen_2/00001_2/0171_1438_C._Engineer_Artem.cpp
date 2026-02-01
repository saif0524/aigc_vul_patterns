#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(n, vector<long long>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i > 0 && a[i][j] == a[i-1][j]){
                    a[i][j]++;
                }
                if(j > 0 && a[i][j] == a[i][j-1]){
                    a[i][j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}