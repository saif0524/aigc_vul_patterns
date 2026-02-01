#include <iostream>
#include <string>

int main() {
    int a;
    std::string s;
    std::cin >> a >> s;
    if (a >= 3200) {
        std::cout << s;
    } else {
        std::cout << "red";
    }
    return 0;
}