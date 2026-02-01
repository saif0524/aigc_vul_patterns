#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    int min_ink = 1e9;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int total = 0;
            for(int k = 0; k < m/2; ++k){
                total += (a[i] % n) + (b[j] % n);
                total += (b[i] % n) + (a[j] % n);
            }
            min_ink = min(min_ink, total);
        }
    }
    cout << min_ink;
}