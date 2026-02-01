#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int count[10] = {0};
    for (char c : s) {
        count[c - '0']++;
    }

    if (count[8] == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    count[8]--;
    std::cout << std::min(count[8], (count[0] + count[1] + count[2] + count[3] + count[4] + count[5] + count[6] + count[7] + count[9]) / 9) << std::endl;
    return 0;
}