#include <iostream>
#include <vector>
#include <string>

std::string to_base(int num, int base) {
    std::string res;
    while (num > 0) {
        int remainder = num % base;
        res = (remainder < 10 ? char('0' + remainder) : char('A' + (remainder - 10))) + res;
        num /= base;
    }
    return res;
}

int main() {
    int k;
    std::cin >> k;

    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            std::cout << to_base(i * j, k) << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}