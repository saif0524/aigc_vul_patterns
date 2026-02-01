#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        vector<long long> vis(n, 0);
        bool valid = true;
        for(long long k = 0; k < n && valid; k++){
            long long new_room = (k + a[k%n] + n) % n;
            if(vis[new_room]){
                valid = false;
            }
            vis[new_room] = 1;
        }
        if(valid){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}