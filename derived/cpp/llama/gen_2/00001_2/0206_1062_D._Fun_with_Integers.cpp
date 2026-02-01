#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (i != n) {
            ans += (n - 1) / i * i + (n - 1) / i;
        }
    }
    cout << ans * 2 << endl;
    return 0;
}