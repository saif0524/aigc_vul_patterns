#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        long long d = *max_element(a.begin(), a.end());
        if(k % 2 == 1){
            for(auto &x: a) x = d - x;
        }
        for(auto &x: a) cout << x << " ";
        cout << "\n";
    }
}