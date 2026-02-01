#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    
    std::sort(s.begin(), s.end());
    do {
        if (s > t) {
            std::cout << s << std::endl;
            return 0;
        }
    } while (std::next_permutation(s.begin(), s.end()));
    
    std::cout << -1 << std::endl;
    return 0;
}