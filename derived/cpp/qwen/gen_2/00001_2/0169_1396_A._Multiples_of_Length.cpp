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
    vector<ll> b(n, 0);
    if(n == 1){
        cout << "1 1\n" << -a[0] << "\n";
        cout << "1 1\n" << 0 << "\n";
        cout << "1 1\n" << 0 << "\n";
        return 0;
    }
    // First operation
    for(int i=0; i<n-1; i++){
        b[i] = -a[i];
    }
    cout << "1 " << n-1 << "\n";
    for(int i=0; i<n-1; i++) cout << b[i] << " ";
    cout << "\n";
    a[n-1] += b[n-2]*(n-1);
    a[n-2] = 0;
    // Second operation
    cout << n-1 << " " << n << "\n";
    cout << -a[n-1]/(n-1) << " " << -a[n-1]/(n-1) << "\n";
    a[n-2] += -a[n-1];
    a[n-1] = 0;
    // Third operation
    cout << "1 " << n << "\n";
    for(int i=0; i<n; i++) cout << -a[i]/n << " ";
    cout << "\n";
}