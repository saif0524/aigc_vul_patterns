#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string n, m;
    std::cin >> n >> m;
    
    std::sort(n.begin(), n.end());
    
    // Remove leading zeros
    auto it = n.find_first_not_of('0');
    if (it != std::string::npos) {
        n = n.substr(it);
    } else {
        n = "0"; // If all are zeros, the smallest number is 0
    }
    
    if (n == m) {
        std::cout << "OK";
    } else {
        std::cout << "WRONG_ANSWER";
    }
    
    return 0;
}