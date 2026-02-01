#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> b[i][j];
        }
    }
    vector<int> a(n, 0);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i != j){
                a[i] |= b[i][j];
            }
        }
    }
    for(int i=0; i<n; ++i){
        cout << a[i] << (i<n-1?" ":"");
    }
    cout << "\n";
}