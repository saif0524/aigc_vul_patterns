#include <iostream>
#include <vector>
#include <string>

bool isZigzag(const std::string& num) {
    if (num.size() == 1) return true;
    for (size_t i = 1; i < num.size(); ++i) {
        if ((i % 2 == 1 && num[i] <= num[i - 1]) || (i % 2 == 0 && num[i] >= num[i - 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string A, B;
    int M;
    std::cin >> A >> B >> M;

    std::string current = A;
    while (true) {
        bool carry = false;
        for (int i = current.size() - 1; i >= 0; --i) {
            int digit = current[i] - '0' + (carry ? 1 : 0);
            digit %= 10;
            current[i] = digit + '0';
            carry = (digit == 0);
            if (!carry) break;
        }
        if (carry) current = "1" + current;

        if (current > B) break;

        std::string modStr;
        long long modValue = 0;
        for (char c : current) {
            modValue = (modValue * 10 + (c - '0')) % M;
        }
        if (modValue == 0 && isZigzag(current)) {
            std::cout << current << std::endl;
        }
    }

    long long count = 0;
    for (long long i = std::stoll(A); i <= std::stoll(B); i += M) {
        if (isZigzag(std::to_string(i))) {
            count++;
        }
    }

    std::cout << count % 10000 << std::endl;
    return 0;
}