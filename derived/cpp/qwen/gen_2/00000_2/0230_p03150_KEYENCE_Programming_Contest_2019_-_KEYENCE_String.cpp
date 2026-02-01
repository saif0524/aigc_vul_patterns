#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string target = "keyence";
    
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = i; j <= s.size(); ++j) {
            std::string modified = s.substr(0, i) + s.substr(j);
            if (modified == target) {
                std::cout << "YES" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}