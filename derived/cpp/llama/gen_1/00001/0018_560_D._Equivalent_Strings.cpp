#include <iostream>
#include <string>

bool is_equivalent(const std::string& a, const std::string& b) {
    if (a == b) return true;
    if (a.size() % 2 != 0) return false;

    size_t half_size = a.size() / 2;
    std::string a1 = a.substr(0, half_size);
    std::string a2 = a.substr(half_size);
    std::string b1 = b.substr(0, half_size);
    std::string b2 = b.substr(half_size);

    return (is_equivalent(a1, b1) && is_equivalent(a2, b2)) ||
           (is_equivalent(a1, b2) && is_equivalent(a2, b1));
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    if (is_equivalent(a, b)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}