#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < x; i++){
        if(i < y){
            if(s[n - x + i] != '1') ans++;
        }
        else{
            if(s[n - x + i] != '0') ans++;
        }
    }
    cout << ans;
    return 0;
}