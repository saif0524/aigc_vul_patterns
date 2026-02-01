#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::string digits;
    std::cin >> digits;

    int count8 = 0;
    for (char c : digits) {
        if (c == '8') {
            count8++;
        }
    }

    int maxPhoneNumbers = count8;
    for (char c : digits) {
        if (c != '8') {
            maxPhoneNumbers = std::min(maxPhoneNumbers, n / 11);
        }
    }

    std::cout << maxPhoneNumbers << std::endl;

    return 0;
}