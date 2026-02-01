#include <iostream>
#include <string>
#include <sstream>

bool check(long long a, long long b, long long mod) {
    for (int i = 0; i <= b; i++) {
        if ((a * 1000000000LL + i) % mod!= 0) return false;
    }
    return true;
}

int main() {
    long long a, b, mod;
    std::cin >> a >> b >> mod;

    if (check(0, b, mod)) {
        std::cout << 2 << std::endl;
        return 0;
    }

    for (int i = 1; i <= a; i++) {
        if (!check(i, b, mod)) {
            std::stringstream ss;
            ss << i;
            std::string s = ss.str();
            while (s.size() < 9) s = "0" + s;
            std::cout << 1 << " " << s << std::endl;
            return 0;
        }
    }

    std::cout << 2 << std::endl;
    return 0;
}