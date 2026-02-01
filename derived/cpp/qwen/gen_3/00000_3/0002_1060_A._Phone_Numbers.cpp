#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int count_8 = std::count(s.begin(), s.end(), '8');
    int total_digits = s.size() - count_8;
    
    int phone_numbers = std::min(count_8, total_digits / 10);
    std::cout << phone_numbers << std::endl;
    
    return 0;
}