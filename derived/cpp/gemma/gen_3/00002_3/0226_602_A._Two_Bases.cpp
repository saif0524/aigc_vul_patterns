#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long baseToDecimal(const vector<int>& digits, int base) {
    long long result = 0;
    for (int digit : digits) {
        result = result * base + digit;
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

    long long x_decimal = baseToDecimal(x, bx);
    long long y_decimal = baseToDecimal(y, by);

    if (x_decimal < y_decimal) {
        cout << '<' << endl;
    } else if (x_decimal > y_decimal) {
        cout << '>' << endl;
    } else {
        cout << '=' << endl;
    }

    return 0;
}