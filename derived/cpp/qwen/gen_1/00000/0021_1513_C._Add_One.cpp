#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long addMod(long long a, long long b) {
    return (a % MOD + b % MOD) % MOD;
}

long long multMod(long long a, long long b) {
    return (a % MOD * b % MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long length = 0;
        while(n > 0){
            int digit = n % 10;
            length = addMod(length, multMod(multMod(m + 1, digit), 1LL));
            n /= 10;
        }
        cout << length << "\n";
    }
}