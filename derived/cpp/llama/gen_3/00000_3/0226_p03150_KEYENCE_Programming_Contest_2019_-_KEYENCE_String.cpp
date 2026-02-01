#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    const std::string target = "keyence";
    bool found = false;

    for (int i = 0; i < S.length(); ++i) {
        for (int j = i + 1; j <= S.length(); ++j) {
            std::string temp = S.substr(0, i) + S.substr(j);
            if (temp == target) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    std::cout << (found ? "YES" : "NO") << std::endl;

    return 0;
}