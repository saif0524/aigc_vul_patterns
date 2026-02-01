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
        int n = s.size();
        int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
        int x = 0, y = 0;
        for(char c : s){
            if(c == 'W') y++;
            if(c == 'S') y--;
            if(c == 'A') x--;
            if(c == 'D') x++;
            max_x = max(max_x, x);
            min_x = min(min_x, x);
            max_y = max(max_y, y);
            min_y = min(min_y, y);
        }
        int original_area = (max_x - min_x + 1) * (max_y - min_y + 1);
        int best_area = original_area;
        string extra = "WASD";
        for(char add : extra){
            int cur_max_x = max_x, cur_min_x = min_x;
            int cur_max_y = max_y, cur_min_y = min_y;
            int cur_x = 0, cur_y = 0;
            for(int i=0; i<=n; i++){
                if(i < n){
                    if(s[i] == 'W') cur_y++;
                    if(s[i] == 'S') cur_y--;
                    if(s[i] == 'A') cur_x--;
                    if(s[i] == 'D') cur_x++;
                }
                if(s[i] != add){
                    continue;
                }
                if(add == 'W') cur_y++;
                if(add == 'S') cur_y--;
                if(add == 'A') cur_x--;
                if(add == 'D') cur_x++;
                cur_max_x = max(cur_max_x, cur_x);
                cur_min_x = min(cur_min_x, cur_x);
                cur_max_y = max(cur_max_y, cur_y);
                cur_min_y = min(cur_min_y, cur_y);
                if(add == 'W') cur_y--;
                if(add == 'S') cur_y++;
                if(add == 'A') cur_x++;
                if(add == 'D') cur_x--;
            }
            int new_area = (cur_max_x - cur_min_x + 1) * (cur_max_y - cur_min_y + 1);
            best_area = min(best_area, new_area);
        }
        cout << best_area << '\n';
    }
}