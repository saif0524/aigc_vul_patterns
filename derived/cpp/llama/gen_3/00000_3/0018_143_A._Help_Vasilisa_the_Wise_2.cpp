#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    int a, b, c, d;
    for (a = 1; a < 10; a++) {
        for (b = 1; b < 10; b++) {
            if (a == b) continue;
            for (c = 1; c < 10; c++) {
                if (c == a || c == b) continue;
                for (d = 1; d < 10; d++) {
                    if (d == a || d == b || d == c) continue;
                    if (a + b == r1 && c + d == r2 &&
                        a + c == c1 && b + d == c2 &&
                        a + d == d1 && b + c == d2) {
                        cout << a << " " << b << endl;
                        cout << c << " " << d << endl;
                        return 0;
                    }
                    if (a + b == r1 && c + d == r2 &&
                        a + d == c1 && b + c == c2 &&
                        a + c == d1 && b + d == d2) {
                        cout << a << " " << b << endl;
                        cout << d << " " << c << endl;
                        return 0;
                    }
                    if (a + b == r2 && c + d == r1 &&
                        a + c == c1 && b + d == c2 &&
                        a + d == d1 && b + c == d2) {
                        cout << c << " " << d << endl;
                        cout << a << " " << b << endl;
                        return 0;
                    }
                    if (a + b == r2 && c + d == r1 &&
                        a + d == c1 && b + c == c2 &&
                        a + c == d1 && b + d == d2) {
                        cout << d << " " << c << endl;
                        cout << a << " " << b << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}