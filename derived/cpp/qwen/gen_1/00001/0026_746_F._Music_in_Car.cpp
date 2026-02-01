#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, w;
    long long k;
    cin >> n >> w >> k;
    vector<int> a(n), t(n);
    for(auto &x: a) cin >> x;
    for(auto &x: t) cin >> x;
    
    int ans = 0;
    for(int start = 0; start < n; ++start){
        int full_listened = 0, partial_listened = 0;
        int current_time = 0;
        long long current_pleasure = 0;
        for(int i = start; i < n && current_time + t[i] - (t[i]/2) <= k; ++i){
            if(current_time + t[i] <= k){
                current_time += t[i];
                current_pleasure += a[i];
                full_listened++;
            }
            else if(partial_listened < w){
                current_time += t[i] / 2;
                current_pleasure += a[i];
                partial_listened++;
            }
            else{
                break;
            }
        }
        ans = max(ans, (int)current_pleasure);
    }
    cout << ans;
}