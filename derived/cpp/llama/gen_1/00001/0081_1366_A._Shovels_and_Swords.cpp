#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        long long emeralds = 0;
        if (a >= b) {
            emeralds += b;
            a -= b;
            emeralds += a / 3;
        } else {
            emeralds += a;
            b -= a * 2;
            emeralds += b / 3;
        }
        std::cout << emeralds << std::endl;
    }
    return 0;
}