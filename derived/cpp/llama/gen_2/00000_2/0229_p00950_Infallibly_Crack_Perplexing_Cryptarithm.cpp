#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int a = 0, b = 0, c = 0;

    for (char ch : s) {
        switch (ch) {
            case 'A':
                a++;
                break;
            case 'C':
                c++;
                break;
            case 'M':
                b++;
                break;
        }
    }

    std::cout << std::min(a, std::min(b, c)) << std::endl;

    return 0;
}