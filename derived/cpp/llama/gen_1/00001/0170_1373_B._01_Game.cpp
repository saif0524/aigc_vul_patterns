#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        bool aliceWins = false;
        int count = 0;

        for (char c : s) {
            if (count == 0 || c != s[count - 1]) {
                count++;
            } else {
                count -= 2;
                if (count < 0) count = 0;
            }
        }

        if (count % 2 == 1) {
            aliceWins = true;
        }

        if (aliceWins) {
            std::cout << "DA" << std::endl;
        } else {
            std::cout << "NET" << std::endl;
        }
    }

    return 0;
}