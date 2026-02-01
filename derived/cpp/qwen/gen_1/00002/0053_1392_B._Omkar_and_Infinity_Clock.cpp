#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        long long max_a = LLONG_MIN;
        for(auto &x: a){
            cin >> x;
            if(x > max_a) max_a = x;
        }
        if(k%2==0){
            for(int i=0;i<n;i++) a[i] = max_a - a[i];
        }
        for(int i=0;i<n;i++) cout << a[i] << (i==n-1?'\n':' ');
    }
}