#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    unordered_map<int, vector<int>> pos_b;
    for(int i=0;i<lb;i++) pos_b[b[i]].push_back(i);
    int ans = 0;
    for(int shift=0;shift<la;shift++){
        int last = -1;
        int current_length = 0;
        for(int i=0;i<la;i++){
            int glyph = a[(i+shift)%la];
            if(pos_b.count(glyph)){
                auto it = upper_bound(pos_b[glyph].begin(), pos_b[glyph].end(), last);
                if(it != pos_b[glyph].end()){
                    last = *it;
                    current_length++;
                }
            }
            else{
                current_length = 0;
                last = -1;
            }
            ans = max(ans, current_length);
        }
    }
    cout << ans;
}