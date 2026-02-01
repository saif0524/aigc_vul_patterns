#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        int len = 0;
        while(n > 0){
            int d = n % 10;
            len += (d + m >= 10 ? 2 : 1);
            n /= 10;
        }
        long long result = 1;
        long long base = 10;
        while(m > 0){
            if(m & 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            m >>= 1;
        }
        len = (len * result) % MOD;
        cout << len << "\n";
    }
}