#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long a = x3 * x3 + y3 * y3;
    long long b = x2 * x3 + y2 * y3;
    long long c = x2 * x2 + y2 * y2;
    long long d = x1 * x3 + y1 * y3;
    long long e = x1 * x2 + y1 * y2;

    if (a == 0) return (x1 == x2 && y1 == y2);

    long long D = b * b - a * c;
    if (D < 0) return false;

    long long D1 = d * y3 - e * x3;
    long long D2 = b * y1 - a * y2;
    long long D3 = x1 * y3 - x3 * y1;

    if (D == 0) return (D1 == 0 && D2 == 0 && D3 == 0);

    long long d1 = D1 * b - D2 * d;
    long long d2 = D1 * e - D3 * d;

    if (d1 % D != 0 || d2 % D != 0) return false;

    d1 /= D;
    d2 /= D;

    if (d1 * d1 + d2 * d2 <= 100000) return true;
    return false;
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<pair<long long, long long>> v1 = {{x1, y1}, {y1, -x1}, {-x1, -y1}, {-y1, x1}};
    vector<pair<long long, long long>> v2 = {{x2, y2}, {y2, -x2}, {-x2, -y2}, {-y2, x2}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (check(v1[i].first, v1[i].second, v2[j].first, v2[j].second, x3, y3)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}