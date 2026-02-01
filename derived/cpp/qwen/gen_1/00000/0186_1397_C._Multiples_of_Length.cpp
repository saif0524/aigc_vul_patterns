#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    if(n==1){
        cout << "1 1\n" << -a[0] << "\n";
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        return 0;
    }
    cout << "1 1\n" << -a[0] << "\n";
    cout << n-1 << n << "\n";
    ll val = a[n-2]+a[n-1];
    cout << val << " " << -val << "\n";
    cout << "2 " << n << "\n";
    for(int i=1;i<n;i++) cout << -a[i]-(i==n-1?val:0) << (i==n-1?"\n":" ");
}