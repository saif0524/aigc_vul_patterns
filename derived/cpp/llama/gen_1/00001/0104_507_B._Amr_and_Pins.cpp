#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, x, y, x2, y2;
    cin >> r >> x >> y >> x2 >> y2;
    long long dist = (x - x2) * (x - x2) + (y - y2) * (y - y2);

    if (dist == 0) {
        cout << 0 << endl;
    } else if (dist <= r * r) {
        cout << 1 << endl;
    } else if (sqrt(dist) <= sqrt(2.0) * r) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}