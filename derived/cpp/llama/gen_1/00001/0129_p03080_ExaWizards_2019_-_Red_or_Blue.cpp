#include <iostream>
#include <string>

int main() {
    int N;
    std::string s;
    std::cin >> N >> s;

    int redCount = 0;
    int blueCount = 0;

    for (char hat : s) {
        if (hat == 'R') {
            redCount++;
        } else {
            blueCount++;
        }
    }

    if (redCount > blueCount) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}