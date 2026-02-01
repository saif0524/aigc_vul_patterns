#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            for(int k1 = 1; k1 <= m; k1++) {
                for(int k2 = k1 + 1; k2 <= m; k2++) {
                    ll a = (k2 - k1) % mod;
                    for(int t = j + 1; t <= i - j; t++) {
                        a = (a * (k2 - k1 + 1)) % mod;
                    }
                    ans += a;
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}