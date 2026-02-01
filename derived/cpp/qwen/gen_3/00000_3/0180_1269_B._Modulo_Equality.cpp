#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long x = -1;
    for(int i=0; i<n; ++i){
        long long diff = (b[i] - a[i] + m) % m;
        if(x == -1) x = diff;
        if((a[i] + x) % m != b[i]){
            cout << "-1";
            return 0;
        }
    }
    cout << x;
}