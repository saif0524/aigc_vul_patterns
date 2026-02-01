#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, V;
    cin >> n >> V;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    double lo = 0, hi = V + 1;
    while(hi - lo > 1e-8){
        double mid = (lo + hi) / 2;
        bool possible = true;
        for(int i=0; i<n; i++){
            if(a[i] * mid > b[i]){
                possible = false;
                break;
            }
        }
        if(possible){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout << fixed << setprecision(10) << lo;
}