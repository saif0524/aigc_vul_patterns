#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    long long count = 0;

    while (n > 0) {
        if (n % 2 == 0) {
            n -= 2;
        } else {
            for (long long d = 3; d <= std::sqrt(n); d += 2) {
                if (n % d == 0) {
                    n -= d;
                    break;
                }
            }
            if (n > 1 && n % 2 != 0) {
                n -= n;
            }
        }
        count++;
    }
    
    std::cout << count;
    return 0;
}