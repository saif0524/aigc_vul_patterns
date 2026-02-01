#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int hours = a;
    int left = a;

    while (left >= b) {
        int newCandles = left / b;
        hours += newCandles;
        left = newCandles + (left % b);
    }

    std::cout << hours << std::endl;

    return 0;
}