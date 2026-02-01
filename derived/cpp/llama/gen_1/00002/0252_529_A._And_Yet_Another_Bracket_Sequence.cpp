#include <iostream>
#include <string>
#include <algorithm>

std::string min_string = "";
int min_open = 1000000000;
int min_close = 1000000000;

void check_string(const std::string& s, int open, int close) {
    if (open < min_open || (open == min_open && close < min_close)) {
        min_open = open;
        min_close = close;
        min_string = s;
    } else if (open == min_open && close == min_close) {
        if (s < min_string) {
            min_string = s;
        }
    }
}

std::string add_brackets(const std::string& s) {
    int balance = 0;
    int open = 0;
    int close = 0;
    std::string res = "";
    for (char c : s) {
        if (balance == -1 && c == ')') {
            res += '(';
            open++;
            balance++;
        }
        res += c;
        if (c == '(') balance++;
        else balance--;
    }
    while (balance != 0) {
        if (balance > 0) {
            res += ')';
            close++;
        } else {
            res.insert(res.begin(), '(');
            open++;
        }
        balance += (balance > 0) ? -1 : 1;
    }
    check_string(res, open, close);
    return res;
}

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    min_string = s + std::string(n, ')');
    min_open = n;
    min_close = n;
    for (int i = 0; i < n; i++) {
        std::string t = s.substr(i, n - i) + s.substr(0, i);
        add_brackets(t);
    }
    std::cout << min_string << std::endl;
    return 0;
}