#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    
    bool isANegative = (a[0] == '-');
    bool isBNegative = (b[0] == '-');
    
    if (isANegative && isBNegative) {
        std::string result = addStrings(a.substr(1), b.substr(1));
        std::cout << "-" << result;
    } else if (isANegative) {
        std::string result;
        if (a.substr(1) > b) {
            result = addStrings(b, a.substr(1));
            std::cout << "-" << result;
        } else if (a.substr(1) < b) {
            result = addStrings(a.substr(1), b);
            std::cout << result;
        } else {
            std::cout << "0";
        }
    } else if (isBNegative) {
        std::string result;
        if (a > b.substr(1)) {
            result = addStrings(a, b.substr(1));
            std::cout << result;
        } else if (a < b.substr(1)) {
            result = addStrings(b.substr(1), a);
            std::cout << "-" << result;
        } else {
            std::cout << "0";
        }
    } else {
        std::cout << addStrings(a, b);
    }
    
    return 0;
}