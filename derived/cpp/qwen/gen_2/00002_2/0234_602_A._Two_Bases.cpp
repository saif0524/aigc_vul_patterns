#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long baseToDecimal(const vector<int>& digits, int base) {
    long long decimal = 0;
    for (int digit : digits) {
        decimal = decimal * base + digit;
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

    long long decimalX = baseToDecimal(x, bx);
    long long decimalY = baseToDecimal(y, by);

    if (decimalX < decimalY) {
        cout << '<' << endl;
    } else if (decimalX > decimalY) {
        cout << '>' << endl;
    } else {
        cout << '=' << endl;
    }

    return 0;
}