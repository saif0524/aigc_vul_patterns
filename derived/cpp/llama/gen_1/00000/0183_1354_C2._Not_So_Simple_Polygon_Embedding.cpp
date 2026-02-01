#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        n *= 2;

        double angle = (n - 2) * PI / n;
        double side = 1 / sin(PI / n);
        double ans = side * cos(PI / n) / cos(angle / 2);
        printf("%.9lf\n", ans);
    }

    return 0;
}