#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n, r;
        cin >> n >> r;
        vector<int> x(n);
        for(auto &xi: x) cin >> xi;
        sort(x.begin(), x.end());
        int ans = 0;
        for(int i = 0; i < n;){
            int cur = x[i];
            while(i < n && x[i] <= cur + r) i++;
            cur = x[i-1] + r;
            while(i < n && x[i] <= cur + r) i++;
            ans++;
        }
        cout << ans << "\n";
    }
}