#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    long long a, b, mod;
    std::cin >> a >> b >> mod;

    if (mod <= b + 1) {
        std::cout << "2" << std::endl;
        return 0;
    }

    for (long long i = 0; i <= a; i++) {
        std::string s = std::to_string(i);
        while (s.length() < 9) s = "0" + s;
        bool win = true;
        for (long long j = 0; j <= b; j++) {
            std::string t = std::to_string(j);
            while (t.length() < 9) t = "0" + t;
            if ((std::stoll(s + t) % mod) == 0) {
                win = false;
                break;
            }
        }
        if (win) {
            std::cout << "1 " << s << std::endl;
            return 0;
        }
    }

    std::cout << "2" << std::endl;
    return 0;
}