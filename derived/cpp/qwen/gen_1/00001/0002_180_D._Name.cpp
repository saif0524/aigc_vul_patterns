#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    
    if (s < t) {
        std::sort(s.begin(), s.end());
        if (s > t) {
            std::cout << s << std::endl;
            return 0;
        }
        while (std::next_permutation(s.begin(), s.end())) {
            if (s > t) {
                std::cout << s << std::endl;
                return 0;
            }
        }
    } else {
        std::sort(s.begin(), s.end());
        while (std::next_permutation(s.begin(), s.end())) {
            if (s > t) {
                std::cout << s << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << "-1" << std::endl;
    return 0;
}