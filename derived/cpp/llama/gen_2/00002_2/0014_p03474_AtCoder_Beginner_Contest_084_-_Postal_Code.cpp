#include <iostream>
#include <string>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::string S;
    std::cin >> S;

    if (S.length()!= A + B + 1) {
        std::cout << "No" << std::endl;
        return 0;
    }

    if (S[A]!= '-') {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (int i = 0; i < A; i++) {
        if (!std::isdigit(S[i])) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    for (int i = A + 1; i < A + B + 1; i++) {
        if (!std::isdigit(S[i])) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}