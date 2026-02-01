#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> target(n, vector<bool>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char c;
            cin >> c;
            target[i][j] = (c == '1');
        }
    }
    int result = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if((i == 0 && j == 0) || (i == 0 && target[i][j] == target[i][j-1]) || (j == 0 && target[i][j] == target[i-1][j])){
                if(target[i][j] != (result%2 == 0)){
                    ++result;
                }
            }else{
                if(target[i][j] != (target[i-1][j] ^ target[i][j-1] ^ result%2)){
                    ++result;
                }
            }
        }
    }
    cout << result;
}