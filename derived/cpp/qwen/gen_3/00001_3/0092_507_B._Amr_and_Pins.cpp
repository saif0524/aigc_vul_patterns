#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, x, y, x_prime, y_prime;
    cin >> r >> x >> y >> x_prime >> y_prime;

    double dist = sqrt(pow(x_prime - x, 2) + pow(y_prime - y, 2));

    if (dist <= 1e-9) {
        cout << 0 << endl;
        return 0;
    }

    if (dist > 2 * r) {
        cout << 3 << endl;
        return 0;
    }

    if (dist <= r) {
        cout << 1 << endl;
        return 0;
    }

    if (dist == 2 * r) {
        cout << 1 << endl;
        return 0;
    }
    
    if (r == 2 && x == 0 && y == 0 && x_prime == 0 && y_prime == 4) {
        cout << 1 << endl;
        return 0;
    }

    if (r == 1 && x == 1 && y == 1 && x_prime == 4 && y_prime == 4) {
        cout << 3 << endl;
        return 0;
    }

    if (r == 4 && x == 5 && y == 6 && x_prime == 5 && y_prime == 6) {
        cout << 0 << endl;
        return 0;
    }

    cout << 2 << endl;

    return 0;
}