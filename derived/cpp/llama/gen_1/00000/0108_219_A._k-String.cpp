#include <iostream>
#include <string>
#include <map>

int main() {
    int k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    std::map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    std::string t;
    for (auto& p : freq) {
        if (p.second % k != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        t += std::string(p.second / k, p.first);
    }

    std::string result;
    for (int i = 0; i < k; i++) {
        result += t;
    }

    std::cout << result << std::endl;

    return 0;
}