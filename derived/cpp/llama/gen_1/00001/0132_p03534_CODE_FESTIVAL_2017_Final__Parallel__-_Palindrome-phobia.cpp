#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int a = 0, b = 0, c = 0;
    for (char ch : s) {
        if (ch == 'a') a++;
        else if (ch == 'b') b++;
        else c++;
    }

    if (a > (s.length() + 1) / 2 || b > (s.length() + 1) / 2 || c > (s.length() + 1) / 2) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}