#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long convertToBase10(const vector<int>& digits, int base) {
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

    long long x_base10 = convertToBase10(x, bx);
    long long y_base10 = convertToBase10(y, by);

    if (x_base10 < y_base10) {
        cout << '<';
    } else if (x_base10 > y_base10) {
        cout << '>';
    } else {
        cout << '=';
    }

    return 0;
}