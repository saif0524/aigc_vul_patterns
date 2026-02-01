#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::string s;

    std::cin >> n >> s;

    std::unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int count8 = freq['8'];
    int countOthers = 0;
    for (char c = '0'; c <= '9'; c++) {
        if (c != '8') {
            countOthers += freq[c];
        }
    }

    if (count8 == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << std::min(count8, countOthers / 10) << std::endl;
    }

    return 0;
}