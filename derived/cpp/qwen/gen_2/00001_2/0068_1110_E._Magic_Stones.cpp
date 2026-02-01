#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> c(n);
    for(auto &x: c) cin >> x;
    vector<ll> t(n);
    for(auto &x: t) cin >> x;
    if(c[0] != t[0] || c[n-1] != t[n-1]){
        cout << "No";
        return 0;
    }
    for(int i=1;i<n-1;i++){
        if(c[i] != t[i]){
            ll diff = t[i] - c[i];
            c[i-1] += diff;
            c[i+1] += diff;
            c[i] = t[i];
        }
    }
    for(int i=1;i<n-1;i++){
        if(c[i] != t[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}