#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string ticket;
    std::cin >> ticket;
    
    int sum1 = (ticket[0] - '0') + (ticket[1] - '0') + (ticket[2] - '0');
    int sum2 = (ticket[3] - '0') + (ticket[4] - '0') + (ticket[5] - '0');
    
    int changes = std::abs(sum1 - sum2) / 9;
    if ((sum1 - sum2) % 9 != 0) {
        changes++;
    }
    
    std::cout << changes;
    
    return 0;
}