#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<int> h(n);
        for(int &x: h) cin >> x;
        int pos = 0;
        while(k--){
            pos = 0;
            while(pos < n-1 && h[pos] >= h[pos+1]) pos++;
            if(pos == n-1){
                cout << -1 << "\n";
                break;
            }
            h[pos]++;
        }
        if(k >= 0) cout << pos+1 << "\n";
    }
}