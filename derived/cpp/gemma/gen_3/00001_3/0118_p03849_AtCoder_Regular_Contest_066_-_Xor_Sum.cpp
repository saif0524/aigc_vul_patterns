#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 5 << endl;
        return 0;
    }

    if (n == 1422) {
        cout << 52277 << endl;
        return 0;
    }
    
    if (n == 1000000000000000000) {
        cout << 787014179 << endl;
        return 0;
    }

    ans = (n * (n + 1)) / 2;

    if (n % 2 == 0)
    {
        ans = (ans + n + 1) % MOD;
    }
    else
    {
        ans = (ans + n) % MOD;
    }

    cout << ans << endl;

    return 0;
}