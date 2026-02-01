#include <iostream>
#include <string>

int main() {
    std::string T;
    std::getline(std::cin, T);

    int Q;
    std::cin >> Q;
    std::cin.ignore();

    for (int i = 0; i < Q; i++) {
        std::string P;
        std::getline(std::cin, P);

        if (T.find(P)!= std::string::npos) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}