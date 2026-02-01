#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = (s[0]-'0') + (s[1]-'0') + (s[2]-'0');
    int b = (s[3]-'0') + (s[4]-'0') + (s[5]-'0');
    int ans = 6;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int na = a - (s[2]-'0') + i;
            int nb = b - (s[3]-'0') + j;
            ans = min(ans, abs(na - nb) + (i != (s[2]-'0')) + (j != (s[3]-'0')));
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int na = a - (s[1]-'0') + i;
            int nb = b - (s[4]-'0') + j;
            ans = min(ans, abs(na - nb) + (i != (s[1]-'0')) + (j != (s[4]-'0')));
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int na = a - (s[0]-'0') + i;
            int nb = b - (s[5]-'0') + j;
            ans = min(ans, abs(na - nb) + (i != (s[0]-'0')) + (j != (s[5]-'0')));
        }
    }
    cout << ans;
}