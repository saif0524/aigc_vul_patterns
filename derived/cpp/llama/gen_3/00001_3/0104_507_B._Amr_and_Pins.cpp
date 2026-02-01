#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    double distance = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));

    if (distance == 0) {
        cout << 0 << endl;
    } else if (distance <= 2 * r) {
        cout << 1 << endl;
    } else if (distance == 2 * r) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}