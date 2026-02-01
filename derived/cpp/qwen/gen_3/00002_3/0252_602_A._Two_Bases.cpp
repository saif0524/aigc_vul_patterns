#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, bx;
    cin >> n >> bx;
    vector<int> x(n);
    for (int &digit : x) cin >> digit;

    int m, by;
    cin >> m >> by;
    vector<int> y(m);
    for (int &digit : y) cin >> digit;

    // Convert X to base 10
    long long x_base10 = 0;
    for (int digit : x) {
        x_base10 = x_base10 * bx + digit;
    }

    // Convert Y to base 10
    long long y_base10 = 0;
    for (int digit : y) {
        y_base10 = y_base10 * by + digit;
    }

    // Compare the two numbers
    if (x_base10 < y_base10) {
        cout << '<';
    } else if (x_base10 > y_base10) {
        cout << '>';
    } else {
        cout << '=';
    }

    return 0;
}