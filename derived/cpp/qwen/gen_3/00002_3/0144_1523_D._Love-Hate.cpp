#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> friends(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '1'){
                friends[i] |= (1<<j);
            }
        }
    }
    int half = (n+1)/2;
    int max_set = 0;
    int result_mask = 0;
    for(int mask = 0; mask < (1<<m); mask++){
        int count = 0;
        for(int friend_mask : friends){
            if(__builtin_popcount(mask & friend_mask) == __builtin_popcount(mask)){
                count++;
            }
        }
        if(count >= half){
            int set_size = __builtin_popcount(mask);
            if(set_size > max_set){
                max_set = set_size;
                result_mask = mask;
            }
        }
    }
    for(int j = 0; j < m; j++){
        if(result_mask & (1<<j)){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
}