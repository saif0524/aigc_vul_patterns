#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int a, b, c;
    iss >> a >> b >> c;

    while (std::getline(std::cin, line)) {
        std::istringstream iss2(line);
        std::string op;
        int x, y;
        iss2 >> op >> x >> y;

        if (op == "L") {
            if (x + y == a) {
                std::cout << b << std::endl;
            } else if (x + y == b) {
                std::cout << a << std::endl;
            } else {
                std::cout << c << std::endl;
            }
        } else if (op == "?") {
            if (x + y == a) {
                std::cout << "L " << b << std::endl;
            } else if (x + y == b) {
                std::cout << "L " << a << std::endl;
            } else {
                std::cout << "L " << c << std::endl;
            }
        }
    }

    return 0;
}