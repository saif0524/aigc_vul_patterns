#include <iostream>
#include <string>

int main() {
    std::string str;
    int num;
    std::cin >> str >> num;

    for (int i = 0; i < str.length(); i++) {
        if (i % num == 0) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
    }

    std::cout << str << std::endl;

    return 0;
}