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
        for(int &i: x) cin >> i;
        sort(x.begin(), x.end());
        int ans = 0;
        for(int i = 0; i < n;){
            int j = i;
            while(j < n && x[j] <= x[i] + r){
                j++;
            }
            ans++;
            i = j;
        }
        cout << ans << "\n";
    }
}