#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int a, c;
    std::cin >> a >> c;

    int b = 0;
    int pow3 = 1;

    while (a > 0 || c > 0) {
        int da = a % 3;
        int dc = c % 3;
        int db = (dc + 3 - da) % 3;
        b += db * pow3;
        a /= 3;
        c /= 3;
        pow3 *= 3;
    }

    std::cout << b << std::endl;

    return 0;
}