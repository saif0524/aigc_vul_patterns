#include <iostream>
#include <string>
#include <algorithm>

std::string rev(const std::string& s) {
    std::string ret = s;
    std::reverse(ret.begin(), ret.end());
    return ret;
}

std::string rotLeft(const std::string& s) {
    return s.substr(1) + s.substr(0, 1);
}

std::string rotRight(const std::string& s) {
    return s.substr(s.size() - 1) + s.substr(0, s.size() - 1);
}

std::string swapHalf(const std::string& s) {
    int mid = s.size() / 2;
    if (s.size() % 2 == 0) {
        return s.substr(mid) + s.substr(0, mid);
    } else {
        return s.substr(mid) + s[mid] + s.substr(0, mid);
    }
}

std::string incrDigits(const std::string& s) {
    std::string ret = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            ret += (c == '9' ? '0' : c + 1);
        } else {
            ret += c;
        }
    }
    return ret;
}

std::string decrDigits(const std::string& s) {
    std::string ret = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            ret += (c == '0' ? '9' : c - 1);
        } else {
            ret += c;
        }
    }
    return ret;
}

void solve(const std::string& order, std::string message) {
    for (int i = order.size() - 1; i >= 0; --i) {
        switch (order[i]) {
            case 'A':
                message = rev(message);
                break;
            case 'J':
                message = rotLeft(message);
                break;
            case 'C':
                message = rotRight(message);
                break;
            case 'E':
                message = swapHalf(message);
                break;
            case 'P':
                message = decrDigits(message);
                break;
            case 'M':
                message = incrDigits(message);
                break;
        }
    }
    std::cout << message << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string order, message;
        std::cin >> order >> message;
        solve(order, message);
    }
    return 0;
}