#include <iostream>
#include <cstdio>

int query(int c, int d) {
    std::cout << "? " << c << " " << d << std::endl;
    std::cout.flush();
    int res;
    std::cin >> res;
    return res;
}

int main() {
    int a = 0, b = 0;
    for (int bit = 29; bit >= 0; --bit) {
        int res1 = query(a | (1 << bit), b);
        int res2 = query(a, b | (1 << bit));
        if (res1 == res2) {
            if (res1 == 1) {
                a |= (1 << bit);
            } else if (res1 == -1) {
                b |= (1 << bit);
            }
        } else {
            a |= (1 << bit);
            b |= (1 << bit);
        }
    }
    std::cout << "! " << a << " " << b << std::endl;
    std::cout.flush();
    return 0;
}