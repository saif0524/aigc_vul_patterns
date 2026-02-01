#include <iostream>
#include <string>
#include <algorithm>

std::string leftRotate(const std::string& str) {
    return str.substr(1) + str[0];
}

std::string rightRotate(const std::string& str) {
    return str[str.size() - 1] + str.substr(0, str.size() - 1);
}

std::string swapHalves(const std::string& str) {
    int mid = str.size() / 2;
    if (str.size() % 2 == 0) {
        return str.substr(mid) + str.substr(0, mid);
    } else {
        return str.substr(mid) + str[mid] + str.substr(0, mid);
    }
}

std::string reverse(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

std::string incrementDigits(const std::string& str) {
    std::string result = str;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] >= '0' && result[i] <= '9') {
            if (result[i] == '9') {
                result[i] = '0';
            } else {
                result[i]++;
            }
        }
    }
    return result;
}

std::string decrementDigits(const std::string& str) {
    std::string result = str;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] >= '0' && result[i] <= '9') {
            if (result[i] == '0') {
                result[i] = '9';
            } else {
                result[i]--;
            }
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string order;
        std::cin >> order;
        std::string message;
        std::cin >> message;

        std::reverse(order.begin(), order.end());

        for (char c : order) {
            switch (c) {
                case 'J':
                    message = leftRotate(message);
                    break;
                case 'C':
                    message = rightRotate(message);
                    break;
                case 'E':
                    message = swapHalves(message);
                    break;
                case 'A':
                    message = reverse(message);
                    break;
                case 'P':
                    message = decrementDigits(message);
                    break;
                case 'M':
                    message = incrementDigits(message);
                    break;
            }
        }

        std::cout << message << std::endl;
    }

    return 0;
}