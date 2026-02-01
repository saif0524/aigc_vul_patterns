#include <iostream>
#include <string>

std::string apply(const std::string& s, char c) {
    std::string r = s;
    if (c == 'J') {
        char t = r[0];
        for (int i = 0; i < r.size() - 1; ++i) r[i] = r[i + 1];
        r[r.size() - 1] = t;
    } else if (c == 'C') {
        char t = r[r.size() - 1];
        for (int i = r.size() - 1; i > 0; --i) r[i] = r[i - 1];
        r[0] = t;
    } else if (c == 'E') {
        int n = r.size() >> 1;
        for (int i = 0; i < n; ++i) {
            std::swap(r[i], r[r.size() - i - 1]);
        }
    } else if (c == 'A') {
        for (int i = 0; i < r.size() >> 1; ++i) {
            std::swap(r[i], r[r.size() - i - 1]);
        }
    } else if (c == 'P') {
        for (int i = 0; i < r.size(); ++i) {
            if (r[i] >= '0' && r[i] <= '9') {
                if (r[i] == '9') r[i] = '0';
                else r[i]++;
            }
        }
    } else if (c == 'M') {
        for (int i = 0; i < r.size(); ++i) {
            if (r[i] >= '0' && r[i] <= '9') {
                if (r[i] == '0') r[i] = '9';
                else r[i]--;
            }
        }
    }
    return r;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string messengers, message;
        std::cin >> messengers >> message;
        for (int i = messengers.size() - 1; i >= 0; --i) {
            message = apply(message, messengers[i]);
        }
        std::cout << message << std::endl;
    }
    return 0;
}