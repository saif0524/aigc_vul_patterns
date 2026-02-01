#include <iostream>

int main() {
    int p;
    std::cin >> p;
    int t = 0;
    while (p >= 10000) {
        t += 10000;
        p -= 10000;
    }
    while (p >= 5000) {
        t += 5000;
        p -= 5000;
    }
    while (p >= 1000) {
        t += 1000;
        p -= 1000;
    }
    while (p >= 500) {
        t += 500;
        p -= 500;
    }
    std::cout << t << std::endl;
    return 0;
}