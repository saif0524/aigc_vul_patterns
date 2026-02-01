#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b;
    std::cin >> c >> d;

    for (int i = 0; ; ++i) {
        int time = b + a * i;
        int j = (time - d) / c;
        if (d + c * j == time && (time - d) % c == 0) {
            std::cout << time << std::endl;
            return 0;
        }
        if (time > 10000) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    return 0;
}