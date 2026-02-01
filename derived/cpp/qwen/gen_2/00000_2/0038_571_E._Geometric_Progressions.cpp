#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> progressions(n);
    for(auto &p : progressions) cin >> p.first >> p.second;
    
    long long ans = -1;
    for(long long x = 1; x <= 1e9; x++){
        bool valid = true;
        for(auto [a, b] : progressions){
            if(x % a != 0){
                valid = false;
                break;
            }
            long long k = x / a;
            if(k == 0){
                if(b != 1){
                    valid = false;
                    break;
                }
            } else {
                long long t = 1;
                while(t <= k){
                    t *= b;
                }
                if(t != k){
                    valid = false;
                    break;
                }
            }
        }
        if(valid){
            ans = x;
            break;
        }
    }
    cout << ans;
}