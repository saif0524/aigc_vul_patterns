#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();

    std::string str;
    std::getline(std::cin, str);

    int x = 0, y = 0;

    for (char c : str) {
        if (c >= 'A' && c <= 'M') y++;
        else if (c >= 'N' && c <= 'Z') y--;
        else if (c >= 'a' && c <= 'm') x++;
        else if (c >= 'n' && c <= 'z') x--;
    }

    int length = std::abs(x) + std::abs(y);
    std::cout << length << std::endl;

    while (x > 0) {
        std::cout << 'a';
        x--;
    }
    while (x < 0) {
        std::cout << 'n';
        x++;
    }
    while (y > 0) {
        std::cout << 'A';
        y--;
    }
    while (y < 0) {
        std::cout << 'N';
        y++;
    }
    std::cout << std::endl;

    return 0;
}