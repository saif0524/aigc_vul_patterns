#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long toDecimal(const vector<int>& digits, int base) {
    long long result = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        result += digits[i] * pow(base, digits.size() - 1 - i);
    }
    return result;
}

int main() {
    int n, bx;
    cin >> n >> bx;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int m, by;
    cin >> m >> by;

    vector<int> y(m);
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }

    long long xDecimal = toDecimal(x, bx);
    long long yDecimal = toDecimal(y, by);

    if (xDecimal < yDecimal) {
        cout << '<' << endl;
    } else if (xDecimal > yDecimal) {
        cout << '>' << endl;
    } else {
        cout << '=' << endl;
    }

    return 0;
}