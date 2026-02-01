#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        vector<long long> assigned(n,0);
        bool valid = true;
        for(long long k = 0; k < 1e9+7; k++){
            long long mod_k = k % n;
            long long new_room = k + a[mod_k];
            if(new_room >= 0){
                new_room %= n;
            } else {
                new_room = (new_room % n + n) % n;
            }
            assigned[new_room]++;
            if(assigned[new_room] > 1){
                valid = false;
                break;
            }
        }
        for(auto x: assigned){
            if(x == 0){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}