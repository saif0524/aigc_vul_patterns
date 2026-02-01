#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    if (s1 == s2) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}