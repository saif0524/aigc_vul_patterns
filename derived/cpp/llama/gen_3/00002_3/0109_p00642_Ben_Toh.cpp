#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        double ans = 0;
        double prob = 1;
        for (int i = 1; i <= n; i++) {
            ans += prob;
            prob /= 2;
            if (prob < 1e-10) {
                prob = 0.5;
            }
        }
        cout << fixed << setprecision(8) << ans << endl;
    }
    return 0;
}