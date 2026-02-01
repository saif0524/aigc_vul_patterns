#include <iostream>
#include <cstdio>

int main() {
    int a = 0, b = 0;
    for (int i = 29; i >= 0; i--) {
        std::printf("? %d %d\n", (a | (1 << i)), b);
        std::fflush(stdout);
        int res;
        std::cin >> res;
        if (res == 1) {
            std::printf("? %d %d\n", a, (b | (1 << i)));
            std::fflush(stdout);
            std::cin >> res;
            if (res == -1) {
                a |= (1 << i);
                b |= (1 << i);
            }
        } else if (res == -1) {
            a |= (1 << i);
        }
    }
    std::printf("! %d %d\n", a, b);
    std::fflush(stdout);
    return 0;
}