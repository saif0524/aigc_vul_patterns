#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    vector<vector<pair<int,int>>> h(b+1);
    vector<vector<pair<int,int>>> v(b+1);
    for(int i=0;i<n;i++){
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if(x0 == x1){
            h[x0].emplace_back(min(y0,y1), max(y0,y1));
        }
        else{
            v[y0].emplace_back(min(x0,x1), max(x0,x1));
        }
    }
    for(int i=0;i<=b;i++){
        sort(h[i].begin(), h[i].end());
        sort(v[i].begin(), v[i].end());
    }
    int q;
    cin >> q;
    while(q--){
        long long x1, y1, t1;
        char w;
        cin >> x1 >> y1 >> w >> t1;
        long long x = x1, y = y1;
        long long t = t1;
        while(t > 0){
            if(w == 'U'){
                auto it = upper_bound(v[y].begin(), v[y].end(), make_pair(x,0LL));
                if(it == v[y].begin()){
                    long long steps = min(t, (long long)x);
                    x -= steps;
                    t -= steps;
                }
                else{
                    --it;
                    long long end = it->second;
                    long long steps = min(t, end - x);
                    x += steps;
                    t -= steps;
                    if(t == 0) break;
                    y += 1;
                    if(y > b){
                        y = b;
                        break;
                    }
                    w = 'R';
                }
            }
            else if(w == 'D'){
                auto it = upper_bound(v[y].begin(), v[y].end(), make_pair(x,0LL));
                if(it == v[y].begin()){
                    long long steps = min(t, (long long)x);
                    x -= steps;
                    t -= steps;
                }
                else{
                    --it;
                    long long end = it->second;
                    long long steps = min(t, end - x);
                    x += steps;
                    t -= steps;
                    if(t == 0) break;
                    y -= 1;
                    if(y < 0){
                        y = 0;
                        break;
                    }
                    w = 'L';
                }
            }
            else if(w == 'L'){
                auto it = upper_bound(h[x].begin(), h[x].end(), make_pair(y,0LL));
                if(it == h[x].begin()){
                    long long steps = min(t, (long long)y);
                    y -= steps;
                    t -= steps;
                }
                else{
                    --it;
                    long long end = it->second;
                    long long steps = min(t, end - y);
                    y += steps;
                    t -= steps;
                    if(t == 0) break;
                    x -= 1;
                    if(x < 0){
                        x = 0;
                        break;
                    }
                    w = 'D';
                }
            }
            else if(w == 'R'){
                auto it = upper_bound(h[x].begin(), h[x].end(), make_pair(y,0LL));
                if(it == h[x].begin()){
                    long long steps = min(t, (long long)y);
                    y -= steps;
                    t -= steps;
                }
                else{
                    --it;
                    long long end = it->second;
                    long long steps = min(t, end - y);
                    y += steps;
                    t -= steps;
                    if(t == 0) break;
                    x += 1;
                    if(x > b){
                        x = b;
                        break;
                    }
                    w = 'U';
                }
            }
        }
        cout << x << " " << y << "\n";
    }
}