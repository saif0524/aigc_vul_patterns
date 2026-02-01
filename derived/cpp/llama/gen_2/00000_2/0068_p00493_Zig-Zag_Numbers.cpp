#include <iostream>
#include <string>
#include <algorithm>

bool isZigzag(long long num) {
    std::string str = std::to_string(num);
    if (str.length() == 1) return true;

    bool increase = str[0] < str[1];
    for (int i = 1; i < str.length() - 1; i++) {
        if (increase && str[i] < str[i + 1]) return false;
        if (!increase && str[i] > str[i + 1]) return false;
        increase = !increase;
    }
    return true;
}

int main() {
    long long A, B, M;
    std::cin >> A >> B >> M;

    int count = 0;
    for (long long i = A; i <= B; i++) {
        if (i % M == 0 && isZigzag(i)) count++;
    }
    std::cout << count % 10000 << std::endl;

    return 0;
}