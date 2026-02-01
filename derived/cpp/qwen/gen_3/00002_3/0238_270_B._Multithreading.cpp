#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i=0; i<n; ++i){
        if(a[i] > i+1) ans++;
    }
    cout << ans;
}