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
    int l = 1, r = n;
    if(a[0] != 0){
        b[0] = -a[0];
        cout << "1 1\n" << b[0] << "\n";
        a[0] = 0;
    }
    l = 1, r = n;
    while(a.back() != 0){
        b.back() = -a.back();
        a.back() = 0;
    }
    cout << n << " " << n << "\n" << b.back() << "\n";
    l = 1, r = n-1;
    while(l <= r){
        if(a[l-1] == 0){
            l++;
            continue;
        }
        if(a[r-1] == 0){
            r--;
            continue;
        }
        ll add = min(-a[l-1],-a[r-1]);
        b[l-1] += add;
        b[r-1] += add;
        a[l-1] += add;
        a[r-1] += add;
        l++, r--;
    }
    cout << "1 " << n-1 << "\n";
    for(int i=0;i<n-1;i++) cout << b[i] << " ";
    cout << "\n";
}