#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int mx_x=0, mn_x=0, mx_y=0, mn_y=0, x=0, y=0;
        for(char c: s){
            if(c == 'W') y--;
            else if(c == 'A') x--;
            else if(c == 'S') y++;
            else if(c == 'D') x++;
            mx_x = max(mx_x, x);
            mn_x = min(mn_x, x);
            mx_y = max(mx_y, y);
            mn_y = min(mn_y, y);
        }
        int best = (mx_x - mn_x + 1) * (mx_y - mn_y + 1);
        x=0, y=0;
        for(int i=0; i<(int)s.size();++i){
            int nmx_x=0, nmn_x=0, nmx_y=0, nmn_y=0;
            for(int j=0; j<(int)s.size();++j){
                if(i == j){
                    if('W' + 'A'+ 'S' + 'D' - s[j] == 'W'){
                        y--;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'A'){
                        x--;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'S'){
                        y++;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'D'){
                        x++;
                    }
                }
                else{
                    if(s[j] == 'W') y--;
                    else if(s[j] == 'A') x--;
                    else if(s[j] == 'S') y++;
                    else if(s[j] == 'D') x++;
                }
                nmx_x = max(nmx_x, x);
                nmn_x = min(nmn_x, x);
                nmx_y = max(nmx_y, y);
                nmn_y = min(nmn_y, y);
            }
            best = min(best, (nmx_x - nmn_x + 1) * (nmx_y - nmn_y + 1));
            x=0, y=0;
        }
        cout << best << "\n";
    }
}