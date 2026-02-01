#include <iostream>
#include <string>

int getLongestOddProperSuprefix(const std::string& s) {
    int n = s.length();
    for (int len = n - 1; len > 0; len -= 2) {
        if (s.find(s.substr(0, len)) != n - len) {
            return len;
        }
    }
    return -1;
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    for (int i = 1; i <= 8; i++) {
        std::string sub = s.substr(i - 1);
        std::cout << getLongestOddProperSuprefix(sub) << " ";
    }
    return 0;
}