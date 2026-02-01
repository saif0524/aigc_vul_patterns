#include <bits/stdc++.h>
using namespace std;

int main(){
    string X;
    cin >> X;
    int s = 0, t = 0;
    for(char c : X){
        if(c == 'S') s++;
        else t++;
    }
    int ans = 0;
    for(char c : X){
        if(c == 'S' && t > 0){
            t--;
        }
        else if(c == 'T' && s > 0){
            s--;
        }
        else{
            ans++;
        }
    }
    cout << ans;
}