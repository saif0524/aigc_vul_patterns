#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count_I = 0, count_A = 0;
    for(char c : s){
        if(c == 'I') count_I++;
        else if(c == 'A') count_A++;
    }
    int can_show = 0;
    for(char c : s){
        if(c == 'I' && count_I + count_A == 1) can_show++;
        else if(c == 'A' && count_A == 1) can_show++;
    }
    cout << can_show;
}