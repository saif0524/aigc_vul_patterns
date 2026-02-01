#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int a = 0, b = 0, c = 0;
    for (char ch : s) {
        if (ch == 'a') a++;
        if (ch == 'b') b++;
        if (ch == 'c') c++;
    }

    if (a > (s.size() / 2) + 1 || b > (s.size() / 2) + 1 || c > (s.size() / 2) + 1) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}