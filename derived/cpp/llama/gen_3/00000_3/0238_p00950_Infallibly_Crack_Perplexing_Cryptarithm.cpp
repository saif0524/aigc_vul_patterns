#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int count = 0;
    for (char c : s) {
        if (c == 'A' || c == 'C' || c == 'M') {
            count++;
        }
    }
    std::cout << 2 * (s.size() - count) + count << std::endl;
    return 0;
}