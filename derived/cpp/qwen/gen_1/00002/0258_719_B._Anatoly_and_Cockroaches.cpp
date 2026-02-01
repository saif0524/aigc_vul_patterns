#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string p1, p2;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) p1 += 'r', p2 += 'b';
        else p1 += 'b', p2 += 'r';
    }
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != p1[i]) c1++;
        if(s[i] != p2[i]) c2++;
    }
    cout << min(c1, c2) / 2 + min(c1, c2) % 2;
    return 0;
}