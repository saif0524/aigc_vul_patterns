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
    if(n == 1){
        cout << a[0] % MOD << "\n";
        return 0;
    }
    vector<long long> b(n-1);
    bool add = true;
    while(n > 1){
        if(add){
            for(int i=0; i<n-1; ++i){
                b[i] = (a[i] + a[i+1]) % MOD;
            }
        }
        else{
            for(int i=0; i<n-1; ++i){
                b[i] = (a[i] - a[i+1] + MOD) % MOD;
            }
        }
        a = b;
        n--;
        add = !add;
    }
    cout << a[0] << "\n";
}