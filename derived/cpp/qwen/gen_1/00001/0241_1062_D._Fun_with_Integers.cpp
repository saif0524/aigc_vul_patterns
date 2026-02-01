#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long ans = 0;
    for(long long x = 2; x*x <= n; ++x){
        for(long long a = 1; a*x <= n; ++a){
            ans += (n/x - a) / (x-1);
        }
    }
    cout << 2 * ans;
}