#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long base_to_decimal(const vector<int>& digits, int base) {
    long long decimal = 0;
    long long power = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        decimal += digits[i] * power;
        power *= base;
    }
    return decimal;
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

    long long decimal_x = base_to_decimal(x, bx);
    long long decimal_y = base_to_decimal(y, by);

    if (decimal_x < decimal_y) {
        cout << "<" << endl;
    } else if (decimal_x > decimal_y) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }

    return 0;
}