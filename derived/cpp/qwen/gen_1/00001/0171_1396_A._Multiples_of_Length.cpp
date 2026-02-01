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
    if(n >= 1){
        ll x = a[0];
        b[0] = -x;
        cout << "1 1\n" << b[0] << "\n";
        a[0] += b[0];
    }
    if(n >= 2){
        ll x = a[1];
        b[1] = -x;
        cout << "2 2\n" << b[1] << "\n";
        a[1] += b[1];
    }
    if(n >= 3){
        ll x = a[2];
        b[2] = -x;
        cout << "3 3\n" << b[2] << "\n";
        a[2] += b[2];
    }
    if(n >= 4){
        for(int i=3;i<n;i++){
            b[i] = -a[i];
            a[i] += b[i];
        }
        cout << "4 " << n << "\n";
        for(int i=3;i<n;i++) cout << b[i] << " ";
        cout << "\n";
    }
}