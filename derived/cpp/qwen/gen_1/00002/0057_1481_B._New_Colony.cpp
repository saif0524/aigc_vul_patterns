#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<int> h(n);
        for(auto &x: h) cin >> x;
        int pos = 0;
        while(k > 0){
            bool moved = false;
            for(int i = pos; i < n - 1; i++){
                if(h[i] >= h[i + 1]){
                    pos = i + 1;
                    moved = true;
                }
                else{
                    h[i]++;
                    k--;
                    moved = false;
                    break;
                }
            }
            if(!moved){
                h[n - 1]++;
                k--;
            }
            if(pos == n - 1 && k > 0){
                k = 0;
                pos = -1;
            }
        }
        cout << pos + 1 << "\n";
    }
}