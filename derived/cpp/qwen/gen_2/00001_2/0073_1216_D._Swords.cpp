#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long g = 0;
    for(int i = 1; i < n; ++i){
        g = __gcd(g, a[i] - a[0]);
    }
    long long z = g;
    long long y = 0;
    for(auto &x : a){
        y += (a[0] - x) / z;
    }
    cout << y << " " << z << "\n";
}