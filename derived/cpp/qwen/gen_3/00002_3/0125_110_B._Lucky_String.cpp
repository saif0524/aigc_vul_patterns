#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    if(n >= 1) s += "a";
    if(n >= 2) s += "b";
    if(n >= 3) s += "c";
    if(n >= 4) s += "a";
    if(n >= 5) s += "b";
    for(int i = 5; i < n; i += 2){
        s += "d";
        if(i + 1 < n) s += "a";
    }
    cout << s;
}