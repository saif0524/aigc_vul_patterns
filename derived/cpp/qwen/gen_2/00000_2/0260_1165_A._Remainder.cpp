#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int operations = 0;
    for(int i = 0; i < x; i++){
        if(i >= y){
            if(s[n-1-i] != '0'){
                operations++;
            }
        }
        else{
            if(s[n-1-i] != '1'){
                operations++;
            }
        }
    }
    cout << operations;
}