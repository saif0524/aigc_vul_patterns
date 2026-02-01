#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long convertToDecimal(const vector<int>& digits, int base) {
    long long decimal = 0;
    for (int i = 0; i < digits.size(); ++i) {
        decimal += digits[i] * pow(base, digits.size() - 1 - i);
    }
    return decimal;
}

int main() {
    int n, bx;
    cin >> n >> bx;

    vector<int> xDigits(n);
    for (int i = 0; i < n; ++i) {
        cin >> xDigits[i];
    }

    int m, by;
    cin >> m >> by;

    vector<int> yDigits(m);
    for (int i = 0; i < m; ++i) {
        cin >> yDigits[i];
    }

    long long xDecimal = convertToDecimal(xDigits, bx);
    long long yDecimal = convertToDecimal(yDigits, by);

    if (xDecimal < yDecimal) {
        cout << "<" << endl;
    } else if (xDecimal > yDecimal) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }

    return 0;
}