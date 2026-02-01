#include <iostream>
#include <string>

std::string extendString(const std::string& s, int k) {
    int n = s.length();
    std::string extended = s;

    for (int i = 0; i < k; i++) {
        extended += s[i % n];
    }

    return extended;
}

bool isTandemRepeat(const std::string& s, int length) {
    int n = s.length();
    if (length > n) return false;

    for (int i = 0; i < length; i++) {
        if (s[i] != s[i + length]) return false;
    }

    return true;
}

int findMaxTandemLength(const std::string& s, int k) {
    std::string extended = extendString(s, k);
    int maxLength = 0;

    for (int length = 1; length <= extended.length() / 2; length++) {
        for (int i = 0; i <= extended.length() - 2 * length; i++) {
            if (isTandemRepeat(extended.substr(i, 2 * length), length)) {
                maxLength = std::max(maxLength, 2 * length);
            }
        }
    }

    return maxLength;
}

int main() {
    std::string s;
    int k;

    std::cin >> s >> k;

    int maxLength = findMaxTandemLength(s, k);

    std::cout << maxLength << std::endl;

    return 0;
}