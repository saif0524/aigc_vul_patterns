#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long a, c;
    cin >> a >> c;

    long long b = 0;
    long long power_of_3 = 1;

    while (a > 0 || c > 0) {
        long long digit_a = a % 10;
        long long digit_c = c % 10;

        long long digit_b = (digit_c - digit_a + 3) % 3;

        b += digit_b * power_of_3;
        power_of_3 *= 10;

        a /= 10;
        c /= 10;
    }

    cout << b << endl;

    return 0;
}