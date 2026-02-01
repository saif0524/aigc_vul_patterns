#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);

    int b1 = 0, r1 = 0, b2 = 0, r2 = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (s[i] == 'r') r1++;
            else b1++;
        } else {
            if (s[i] == 'r') r2++;
            else b2++;
        }
    }

    std::cout << std::min(std::max(b1, r1), std::max(b2, r2)) << std::endl;

    return 0;
}