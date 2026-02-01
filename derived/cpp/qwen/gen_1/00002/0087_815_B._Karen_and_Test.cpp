#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    while(n > 1){
        for(int i = 0; i < n - 1; ++i){
            if(i % 2 == 0){
                a[i] = (a[i] + a[i + 1]) % MOD;
            }
            else{
                a[i] = (a[i] - a[i + 1] + MOD) % MOD;
            }
        }
        n--;
    }
    cout << a[0];
}