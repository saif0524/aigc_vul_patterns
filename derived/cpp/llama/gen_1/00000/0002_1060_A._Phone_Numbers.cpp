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
    int count8 = count[8];
    count[0] += count[8];
    int ans = count8;
    for (int i = 1; i <= 9; i++) {
        ans = std::min(ans, count[i]);
    }
    std::cout << std::min(count8, std::min(ans, count[0] / 10)) << std::endl;
    return 0;
}