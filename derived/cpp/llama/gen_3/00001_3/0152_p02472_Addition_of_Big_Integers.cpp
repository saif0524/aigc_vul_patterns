#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;

    std::string result;
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back('0' + sum % 10);
        carry = sum / 10;
    }

    if (carry) result.push_back('0' + carry);

    std::reverse(result.begin(), result.end());

    while (result.size() > 1 && result[0] == '0') result.erase(0, 1);

    std::cout << result << std::endl;

    return 0;
}