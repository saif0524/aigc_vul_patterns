#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    int red = 0, blue = 0;
    for(char c : s){
        if(c == 'R') red++;
        else blue++;
    }
    if(red > blue) cout << "Yes";
    else cout << "No";
    return 0;
}