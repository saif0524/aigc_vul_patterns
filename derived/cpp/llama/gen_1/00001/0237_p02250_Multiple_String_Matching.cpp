#include <iostream>
#include <string>

int main() {
    std::string T;
    std::cin >> T;

    int Q;
    std::cin >> Q;

    while (Q-- > 0) {
        std::string P;
        std::cin >> P;

        if (T.find(P) != std::string::npos) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}