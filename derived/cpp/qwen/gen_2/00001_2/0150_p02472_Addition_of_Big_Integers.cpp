#include <iostream>
#include <string>
#include <algorithm>

std::string addBigIntegers(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    bool isNegative = false;
    if (a[0] == '-' && b[0] == '-') {
        isNegative = true;
        a = a.substr(1);
        b = b.substr(1);
    } else if (a[0] == '-') {
        a = a.substr(1);
        if (a < b) {
            result = addBigIntegers(b, a);
            result.insert(0, "-");
        } else {
            result = addBigIntegers(a, b);
        }
        std::cout << result << std::endl;
        return 0;
    } else if (b[0] == '-') {
        b = b.substr(1);
        if (b < a) {
            result = addBigIntegers(a, b);
        } else {
            result = addBigIntegers(b, a);
            result.insert(0, "-");
        }
        std::cout << result << std::endl;
        return 0;
    }

    std::string result = addBigIntegers(a, b);
    if (isNegative) result.insert(0, "-");
    std::cout << result << std::endl;

    return 0;
}