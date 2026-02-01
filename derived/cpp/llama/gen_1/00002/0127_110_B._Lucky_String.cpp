#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    for (int i = 0; i < n; ++i) {
        s += 'a' + (i % 4);
    }

    std::cout << s << std::endl;

    return 0;
}