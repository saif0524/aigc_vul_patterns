#include <iostream>
#include <string>
#include <sstream>

std::string convertToBase(int number, int base) {
    if (number == 0) return "0";
    std::string result = "";
    while (number > 0) {
        int remainder = number % base;
        if (remainder < 10) result = std::to_string(remainder) + result;
        else result = char('A' + remainder - 10) + result;
        number = number / base;
    }
    return result;
}

int main() {
    int k;
    std::cin >> k;

    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            std::cout << convertToBase(i * j, k) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}