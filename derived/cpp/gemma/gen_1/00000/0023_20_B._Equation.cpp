#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (a == 0) {
        double root = -c / b;
        cout << 1 << endl;
        cout << fixed << setprecision(10) << root << endl;
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        cout << 0 << endl;
        return 0;
    }

    if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << 1 << endl;
        cout << fixed << setprecision(10) << root << endl;
        return 0;
    }

    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);

    if (root1 > root2) {
        swap(root1, root2);
    }

    cout << 2 << endl;
    cout << fixed << setprecision(10) << root1 << endl;
    cout << fixed << setprecision(10) << root2 << endl;

    return 0;
}