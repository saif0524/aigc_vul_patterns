#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        while (b >= 2 && c >= 2) {
            ans += 3;
            b -= 2;
            c -= 2;
        }
        while (a >= 1 && b >= 2) {
            ans += 3;
            a -= 1;
            b -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}