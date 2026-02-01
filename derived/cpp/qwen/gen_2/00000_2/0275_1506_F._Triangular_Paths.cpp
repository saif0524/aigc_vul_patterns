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
        vector<long long> r(n), c(n);
        for(auto &x: r) cin >> x;
        for(auto &x: c) cin >> x;
        long long cost = 0;
        for(int i = 1; i < n; i++){
            long long dr = r[i] - r[i-1];
            long long dc = c[i] - c[i-1];
            if(dr == dc){
                cost += 0;
            }
            else if(dr > dc){
                long long diff = dr - dc;
                if((r[i-1] + c[i-1]) % 2 == 0){
                    cost += diff / 2;
                }
                else{
                    cost += (diff + 1) / 2;
                }
            }
            else{
                long long diff = dc - dr;
                if((r[i-1] + c[i-1]) % 2 == 0){
                    cost += (diff + 1) / 2;
                }
                else{
                    cost += diff / 2;
                }
            }
        }
        cout << cost << "\n";
    }
}