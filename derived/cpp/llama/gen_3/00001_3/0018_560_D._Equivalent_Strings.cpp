#include <iostream>
#include <string>

bool isEquivalent(const std::string& a, const std::string& b) {
    if (a == b) return true;
    if (a.size() % 2!= 0) return false;

    int mid = a.size() / 2;
    std::string a1 = a.substr(0, mid);
    std::string a2 = a.substr(mid);
    std::string b1 = b.substr(0, mid);
    std::string b2 = b.substr(mid);

    return (isEquivalent(a1, b1) && isEquivalent(a2, b2)) ||
           (isEquivalent(a1, b2) && isEquivalent(a2, b1));
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    if (isEquivalent(a, b)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}