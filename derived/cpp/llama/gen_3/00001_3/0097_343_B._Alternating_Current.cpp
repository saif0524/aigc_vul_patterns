#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int count = 0;
    for (char c : s) {
        if (c == '+') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    if (count == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}