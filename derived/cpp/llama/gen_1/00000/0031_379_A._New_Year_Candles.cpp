#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int hours = a;
    int remaining = a;
    while (remaining >= b) {
        int newCandles = remaining / b;
        hours += newCandles;
        remaining = newCandles + (remaining % b);
    }
    std::cout << hours << std::endl;
    return 0;
}