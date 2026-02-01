#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string str;
    std::cin >> str;

    int cnt = 0;
    int pos = str.size() - 1;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == '#') {
            if (cnt == 0) {
                std::cout << "-1\n";
                return 0;
            }
            str[i] = ')';
            pos = i;
            --cnt;
        } else if (str[i] == ')') {
            ++cnt;
        } else {
            --cnt;
        }
    }

    cnt = 0;
    for (int i = 0; i <= pos; ++i) {
        if (str[i] == '#') {
            if (cnt == 0) {
                std::cout << "-1\n";
                return 0;
            }
            str[i] = ')';
            --cnt;
        } else if (str[i] == ')') {
            ++cnt;
        } else {
            --cnt;
        }

        if (cnt < 0) {
            std::cout << "-1\n";
            return 0;
        }
    }

    cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++cnt;
        } else {
            --cnt;

            if (cnt < 0) {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    if (cnt != 0) {
        std::cout << "-1\n";
        return 0;
    }

    int sum = 0;
    for (char c : str) {
        if (c == ')') {
            ++sum;
        } else if (c == '(') {
            --sum;
        }
    }

    int j = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '#') {
            std::cout << sum + j + 1 << '\n';
            ++j;
        }
    }

    return 0;
}