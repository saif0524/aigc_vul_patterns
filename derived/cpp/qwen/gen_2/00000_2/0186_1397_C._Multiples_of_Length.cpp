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
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    
    // Operation 1
    ll sum1 = 0;
    for(int i=0;i<n-1;i++){
        b[i] = -a[i];
        sum1 += b[i];
    }
    b[n-1] = -sum1 - a[n-1];
    cout << "1 " << n << "\n";
    for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    
    // Reset b
    fill(b.begin(), b.end(), 0);
    ll sum2 = 0;
    for(int i=1;i<n;i++){
        b[i] = -a[i];
        sum2 += b[i];
    }
    b[0] = -sum2 - a[0];
    cout << "1 " << n << "\n";
    for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    
    // Reset b
    fill(b.begin(), b.end(), 0);
    if(n >= 3){
        b[n-1] = sum1 + sum2 + 2*a[n-1];
        cout << n << " " << n << "\n";
        cout << b[n-1] << "\n";
    } else {
        cout << "1 1\n";
        cout << "0\n";
    }
}