#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    vector<double> results(12);
    vector<string> expressions = {
        "x^y^z", "(x^y)^z", "(x^z)^y", "yx^z", "y^x^z", "(y^z)^x",
        "zx^y", "(z^x)^y", "z^y^x", "(z^y)^x", "(z^x)^y", "y^z^x"
    };

    results[0] = pow(x, pow(y, z));
    results[1] = pow(pow(x, y), z);
    results[2] = pow(pow(x, z), y);
    results[3] = pow(y, pow(x, z));
    results[4] = pow(y, pow(z, x));
    results[5] = pow(pow(y, z), x);
    results[6] = pow(z, pow(x, y));
    results[7] = pow(pow(z, x), y);
    results[8] = pow(z, pow(y, x));
    results[9] = pow(pow(z, y), x);
    results[10] = pow(pow(z, x), y);
    results[11] = pow(y, pow(z, x));

    double max_value = results[0];
    int max_index = 0;

    for (int i = 1; i < 12; ++i) {
        if (results[i] > max_value) {
            max_value = results[i];
            max_index = i;
        }
    }

    cout << expressions[max_index] << endl;

    return 0;
}