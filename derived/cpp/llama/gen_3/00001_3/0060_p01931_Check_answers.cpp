#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int count = 0;
    int consecutiveX = 0;

    for (char c : s) {
        count++;
        if (c == 'x') {
            consecutiveX++;
            if (consecutiveX == 2) {
                break;
            }
        } else {
            consecutiveX = 0;
        }
    }

    std::cout << count << std::endl;

    return 0;
}