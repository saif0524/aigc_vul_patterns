#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll factorial(int n) {
    ll res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool valid(int n) {
    return n >= 8 && (n % 2 == 1 || (n % 2 == 0 && n >= 16));
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        if (!valid(n)) {
            cout << 0 << endl;
            continue;
        }
        ll ans = factorial(8);
        if (n % 2 == 0) {
            ans /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}