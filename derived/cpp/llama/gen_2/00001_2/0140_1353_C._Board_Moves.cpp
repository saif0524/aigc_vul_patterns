#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        long long ans = (n * n - 1) / 2;
        cout << ans << endl;
    }
    return 0;
}