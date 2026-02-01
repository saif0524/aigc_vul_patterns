#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int count = 0;
        for (char c : s) {
            if (c == '1') {
                count++;
            }
        }

        if (count % 2 == 1 || s.size() % 2 == 1) {
            std::cout << "DA" << std::endl;
        } else {
            std::cout << "NET" << std::endl;
        }
    }

    return 0;
}