#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> target(n);
    for(auto &row : target) cin >> row;
    
    vector<string> current(n, string(n, '0'));
    int commands = 0;
    
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            if(current[x][y] != target[x][y]){
                ++commands;
                for(int i = x; i <= y; ++i){
                    current[x][i] = (current[x][i] == '0') ? '1' : '0';
                    current[i][y] = (current[i][y] == '0') ? '1' : '0';
                }
            }
        }
    }
    
    cout << commands;
}