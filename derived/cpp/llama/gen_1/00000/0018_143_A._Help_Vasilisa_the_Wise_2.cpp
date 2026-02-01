#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> r(2);
    vector<int> c(2);
    vector<int> d(2);

    cin >> r[0] >> r[1];
    cin >> c[0] >> c[1];
    cin >> d[0] >> d[1];

    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            if (a == b) continue;
            for (int c1 = 1; c1 <= 9; ++c1) {
                if (c1 == a || c1 == b) continue;
                for (int d1 = 1; d1 <= 9; ++d1) {
                    if (d1 == a || d1 == b || d1 == c1) continue;
                    if (a + b == r[0] && c1 + d1 == r[1] &&
                        a + c1 == c[0] && b + d1 == c[1] &&
                        a + d1 == d[0] && b + c1 == d[1]) {
                        cout << a << " " << b << endl;
                        cout << c1 << " " << d1 << endl;
                        return 0;
                    }
                    if (a + b == r[0] && c1 + d1 == r[1] &&
                        a + d1 == c[0] && b + c1 == c[1] &&
                        a + c1 == d[0] && b + d1 == d[1]) {
                        cout << a << " " << b << endl;
                        cout << d1 << " " << c1 << endl;
                        return 0;
                    }
                    if (a + c1 == r[0] && b + d1 == r[1] &&
                        a + b == c[0] && c1 + d1 == c[1] &&
                        a + d1 == d[0] && b + c1 == d[1]) {
                        cout << a << " " << c1 << endl;
                        cout << b << " " << d1 << endl;
                        return 0;
                    }
                    if (a + c1 == r[0] && b + d1 == r[1] &&
                        a + d1 == c[0] && b + c1 == c[1] &&
                        a + b == d[0] && c1 + d1 == d[1]) {
                        cout << a << " " << c1 << endl;
                        cout << d1 << " " << b << endl;
                        return 0;
                    }
                    if (a + d1 == r[0] && b + c1 == r[1] &&
                        a + b == c[0] && c1 + d1 == c[1] &&
                        a + c1 == d[0] && b + d1 == d[1]) {
                        cout << a << " " << d1 << endl;
                        cout << b << " " << c1 << endl;
                        return 0;
                    }
                    if (a + d1 == r[0] && b + c1 == r[1] &&
                        a + d1 == c[0] && b + c1 == c[1] &&
                        a + b == d[0] && c1 + d1 == d[1]) {
                        cout << a << " " << d1 << endl;
                        cout << c1 << " " << b << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}