#include <iostream>
#include <iomanip>

using namespace std;

double solve(int n) {
    double f[40] = {0};
    f[0] = 1;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double tmp = 0;
        for (int j = 0; j < 30; j++) {
            tmp += f[j] / (1 << j);
        }
        ans += tmp;
        for (int j = 29; j > 0; j--) {
            f[j] = f[j - 1] * (1 - 1.0 / (1 << (j - 1)));
        }
        f[0] = 1 - tmp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << solve(n) << "\n";
    }
    return 0;
}