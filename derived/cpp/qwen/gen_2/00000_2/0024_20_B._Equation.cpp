#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    vector<double> roots;

    if (A == 0) {
        if (B == 0) {
            if (C == 0) {
                cout << -1;
            } else {
                cout << 0;
            }
        } else {
            roots.push_back(-static_cast<double>(C) / B);
        }
    } else {
        double discriminant = static_cast<double>(B) * B - 4 * A * C;
        if (discriminant > 0) {
            roots.push_back((-B + sqrt(discriminant)) / (2.0 * A));
            roots.push_back((-B - sqrt(discriminant)) / (2.0 * A));
        } else if (discriminant == 0) {
            roots.push_back(-static_cast<double>(B) / (2.0 * A));
        }
    }

    sort(roots.begin(), roots.end());
    cout << roots.size() << endl;
    for (double root : roots) {
        cout << fixed << setprecision(10) << root << endl;
    }

    return 0;
}