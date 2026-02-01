#include <bits/stdc++.h>
using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    if (A == 0) {
        if (B == 0) {
            if (C == 0) {
                cout << -1 << endl;
                return 0;
            }
            cout << 0 << endl;
            return 0;
        }
        cout << 1 << endl;
        printf("%.10f\n", -C / B);
        return 0;
    }

    double D = B * B - 4 * A * C;

    if (D < 0) {
        cout << 0 << endl;
        return 0;
    }

    if (D == 0) {
        cout << 1 << endl;
        printf("%.10f\n", -B / (2 * A));
        return 0;
    }

    cout << 2 << endl;
    double x1 = (-B - sqrt(D)) / (2 * A);
    double x2 = (-B + sqrt(D)) / (2 * A);

    if (x1 > x2) swap(x1, x2);
    printf("%.10f\n", x1);
    printf("%.10f\n", x2);

    return 0;
}