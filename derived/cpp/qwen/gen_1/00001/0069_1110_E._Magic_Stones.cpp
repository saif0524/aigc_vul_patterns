#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> c(n), t(n);
    for(auto &x: c) cin >> x;
    for(auto &x: t) cin >> x;
    for(int i=1;i<n-1;i++){
        long long diff = t[i] - c[i];
        c[i+1] += diff;
        c[i-1] += diff;
        c[i] -= diff;
    }
    if(c==t) cout << "Yes";
    else cout << "No";
}