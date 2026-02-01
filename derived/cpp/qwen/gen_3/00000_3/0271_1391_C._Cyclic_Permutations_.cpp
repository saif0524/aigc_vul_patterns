#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll modPow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (modPow(2, n) - 2 + MOD) % MOD;
    } else {
        cout << (modPow(2, n) - 1 + MOD) % MOD;
    }
    return 0;
}