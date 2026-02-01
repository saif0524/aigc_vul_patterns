#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    set<pair<long long, long long>> cuts_x, cuts_y;
    cuts_x.insert({0, n});
    cuts_y.insert({0, m});
    for(long long i=0;i<k;i++){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            cuts_x.insert({min(y1, y2), max(y1, y2)});
        }
        else{
            cuts_y.insert({min(x1, x2), max(x1, x2)});
        }
    }
    vector<long long> widths_x, widths_y;
    long long last = -1;
    for(auto it : cuts_x){
        if(last != -1){
            widths_y.push_back(it.first - last);
        }
        last = it.second;
    }
    last = -1;
    for(auto it : cuts_y){
        if(last != -1){
            widths_x.push_back(it.first - last);
        }
        last = it.second;
    }
    long long even_w_x = 0, odd_w_x = 0, even_w_y = 0, odd_w_y = 0;
    for(auto w : widths_x){
        if(w & 1){
            odd_w_x++;
        }
        else{
            even_w_x++;
        }
    }
    for(auto w : widths_y){
        if(w & 1){
            odd_w_y++;
        }
        else{
            even_w_y++;
        }
    }
    long long nim_sum = 0;
    if(odd_w_x > 0){
        nim_sum ^= (even_w_x + 1);
    }
    if(even_w_x > 0){
        nim_sum ^= even_w_x;
    }
    if(odd_w_y > 0){
        nim_sum ^= (even_w_y + 1);
    }
    if(even_w_y > 0){
        nim_sum ^= even_w_y;
    }
    if(nim_sum == 0){
        cout << "SECOND";
    }
    else{
        cout << "FIRST\n";
        if(odd_w_x > 0){
            long long cnt = 0, last_pos = 0;
            for(auto it : cuts_x){
                if(cnt == (even_w_x)){
                    long long mid = (last_pos + it.first) / 2;
                    cout << mid << " " << last_pos << " " << mid << " " << it.first;
                    return 0;
                }
                cnt++;
                last_pos = it.second;
            }
        }
        if(even_w_x > 0){
            long long cnt = 0, last_pos = 0;
            for(auto it : cuts_x){
                if(cnt == (even_w_x - 1)){
                    long long mid = (last_pos + it.first) / 2;
                    cout << mid << " " << last_pos << " " << mid << " " << it.first;
                    return 0;
                }
                cnt++;
                last_pos = it.second;
            }
        }
        if(odd_w_y > 0){
            long long cnt = 0, last_pos = 0;
            for(auto it : cuts_y){
                if(cnt == (even_w_y)){
                    long long mid = (last_pos + it.first) / 2;
                    cout << last_pos << " " << mid << " " << it.first << " " << mid;
                    return 0;
                }
                cnt++;
                last_pos = it.second;
            }
        }
        if(even_w_y > 0){
            long long cnt = 0, last_pos = 0;
            for(auto it : cuts_y){
                if(cnt == (even_w_y - 1)){
                    long long mid = (last_pos + it.first) / 2;
                    cout << last_pos << " " << mid << " " << it.first << " " << mid;
                    return 0;
                }
                cnt++;
                last_pos = it.second;
            }
        }
    }
}