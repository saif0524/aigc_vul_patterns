#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int a, c;
    std::cin >> a >> c;

    std::string a_str, c_str;
    while (a > 0) {
        a_str += (a % 3) + '0';
        a /= 3;
    }
    std::reverse(a_str.begin(), a_str.end());

    while (c > 0) {
        c_str += (c % 3) + '0';
        c /= 3;
    }
    std::reverse(c_str.begin(), c_str.end());

    int max_len = std::max(a_str.length(), c_str.length());
    a_str.insert(0, max_len - a_str.length(), '0');
    c_str.insert(0, max_len - c_str.length(), '0');

    std::string b_str;
    for (int i = 0; i < max_len; ++i) {
        int digit = (c_str[i] - '0') - (a_str[i] - '0');
        if (digit < 0) digit += 3;
        b_str += digit + '0';
    }

    long long b = 0;
    long long p = 1;
    for (int i = b_str.length() - 1; i >= 0; --i) {
        b += (b_str[i] - '0') * p;
        p *= 3;
    }

    std::cout << b << std::endl;

    return 0;
}