#include <iostream>
#include <vector>
#include <string>

std::string toBase(int num, int base) {
    if (num == 0) return "0";
    std::string result;
    while (num > 0) {
        result += (num % base) + '0';
        num /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int k;
    std::cin >> k;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            std::cout << toBase(i * j, k);
            if (j < k - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}