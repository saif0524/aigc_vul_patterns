#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &x: A) cin >> x;
    
    long long ans = 0;
    for(int b=0;b<60;b++){
        long long cnt = 0;
        for(auto &x: A){
            if(x & (1LL << b)) cnt++;
        }
        ans = (ans + (cnt * (N - cnt) * (1LL << b)) % MOD) % MOD;
    }
    cout << ans;
}