#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int n = min(100, k*3);
    vector<vector<char>> g(n, vector<char>(n, '0'));
    int cnt = 0;
    for(int i=0; i<n && cnt < k; ++i){
        for(int j=i+1; j<n && cnt < k; ++j){
            for(int l=j+1; l<n && cnt < k; ++l){
                g[i][j] = g[j][i] = '1';
                g[j][l] = g[l][j] = '1';
                g[l][i] = g[i][l] = '1';
                ++cnt;
            }
        }
    }
    cout << n << "\n";
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << g[i][j];
        }
        cout << "\n";
    }
}