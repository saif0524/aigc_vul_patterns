#include <iostream>
#include <string>

int main() {
    std::string A, B, C;
    std::cin >> A >> B >> C;
    if (A.back() == B.front() && B.back() == C.front()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}