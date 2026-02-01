#include <iostream>
#include <vector>
#include <string>

int main() {
    long long a, b;
    std::cin >> a >> b;

    if (b == 0) {
        std::cout << a * a << std::endl;
        for (int i = 0; i < a; i++) std::cout << 'o';
        return 0;
    }

    long long ans = -1000000000000000000;
    std::string ans_s;

    for (int i = 1; i <= b; i++) {
        long long cur = 0;
        long long x = b / i;
        long long cnt = b % i;
        for (int j = 0; j < i; j++) {
            if (j < cnt) cur -= (x + 1) * (x + 1);
            else cur -= x * x;
        }
        if (a > 0) cur += a * a;
        if (cur > ans) {
            ans = cur;
            ans_s = "";
            for (int j = 0; j < i; j++) {
                if (j < cnt) {
                    for (int k = 0; k < x + 1; k++) ans_s += 'x';
                } else {
                    for (int k = 0; k < x; k++) ans_s += 'x';
                }
                if (j < i - 1) {
                    if (a > 0) {
                        ans_s += 'o';
                        a--;
                    }
                }
            }
            while (a > 0) {
                ans_s += 'o';
                a--;
            }
        }
    }

    std::cout << ans << std::endl;
    std::cout << ans_s << std::endl;

    return 0;
}