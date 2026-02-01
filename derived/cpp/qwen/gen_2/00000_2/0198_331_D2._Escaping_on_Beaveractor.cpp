#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> ver, hor;
    for(int i=0; i<n; i++){
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if(x0 == x1) ver.push_back({max(y0, y1), min(y0, y1)});
        else hor.push_back({max(x0, x1), min(x0, x1)});
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    int q;
    cin >> q;
    while(q--){
        int x, y, t;
        char w;
        cin >> x >> y >> w >> t;
        vector<pair<int, int>>::iterator it;
        if(w == 'U'){
            for(int i=0; i<t; i++){
                it = lower_bound(hor.begin(), hor.end(), make_pair(x+1, -1));
                if(it != hor.begin()){
                    it--;
                    if((*it).first > x){
                        y++;
                        if(y > b){
                            y--;
                            break;
                        }
                    }else{
                        y = (*it).second+1;
                        x--;
                    }
                }else{
                    y++;
                    if(y > b){
                        y--;
                        break;
                    }
                }
            }
        }else if(w == 'D'){
            for(int i=0; i<t; i++){
                it = lower_bound(hor.begin(), hor.end(), make_pair(x-1, -1));
                if(it != hor.end() && (*it).second <= x){
                    y--;
                    if(y < 0){
                        y++;
                        break;
                    }
                }else{
                    it = lower_bound(hor.begin(), hor.end(), make_pair(x, -1));
                    if(it != hor.end() && (*it).first > x){
                        y = (*it).second;
                        x++;
                    }else{
                        y--;
                        if(y < 0){
                            y++;
                            break;
                        }
                    }
                }
            }
        }else if(w == 'L'){
            for(int i=0; i<t; i++){
                it = lower_bound(ver.begin(), ver.end(), make_pair(y-1, -1));
                if(it != ver.end() && (*it).second <= y){
                    x--;
                    if(x < 0){
                        x++;
                        break;
                    }
                }else{
                    it = lower_bound(ver.begin(), ver.end(), make_pair(y, -1));
                    if(it != ver.end() && (*it).first > y){
                        x = (*it).second;
                        y++;
                    }else{
                        x--;
                        if(x < 0){
                            x++;
                            break;
                        }
                    }
                }
            }
        }else{
            for(int i=0; i<t; i++){
                it = lower_bound(ver.begin(), ver.end(), make_pair(y+1, -1));
                if(it != ver.begin()){
                    it--;
                    if((*it).first > y){
                        x++;
                        if(x > b){
                            x--;
                            break;
                        }
                    }else{
                        x = (*it).second+1;
                        y--;
                    }
                }else{
                    x++;
                    if(x > b){
                        x--;
                        break;
                    }
                }
            }
        }
        cout << x << " " << y << "\n";
    }
}