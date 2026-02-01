#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;

    std::cin >> n >> s;

    int consecutiveX = 0;
    int answered = 0;

    for (char c : s) {
        if (c == 'x') {
            consecutiveX++;
        } else {
            consecutiveX = 0;
        }
        answered++;

        if (consecutiveX == 2) {
            break;
        }
    }

    std::cout << answered << std::endl;

    return 0;
}