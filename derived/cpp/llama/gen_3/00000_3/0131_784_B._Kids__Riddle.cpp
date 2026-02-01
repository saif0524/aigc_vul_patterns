#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int cnt = 0;
    while(n > 0 && n % 2 == 0) {
        n /= 2;
        cnt++;
    }

    if(n == 0) {
        std::cout << cnt << std::endl;
    } else if(std::sqrt(n) == (int)std::sqrt(n)) {
        std::cout << 2 << std::endl;
    } else if(n % 2 == 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}