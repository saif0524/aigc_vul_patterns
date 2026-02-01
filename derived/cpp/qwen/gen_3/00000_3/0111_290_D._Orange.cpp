#include <iostream>
#include <string>

int main() {
    std::string input;
    int shift;
    std::cin >> input >> shift;

    for (char& c : input) {
        if (shift == 0) break;
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + shift) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + shift) % 26) + 'A';
        }
    }

    std::cout << input << std::endl;
    return 0;
}