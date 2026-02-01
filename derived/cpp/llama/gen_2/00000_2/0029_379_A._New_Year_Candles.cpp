#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int hours = a;
    int burnedCandles = a;

    while (burnedCandles >= b) {
        int newCandles = burnedCandles / b;
        hours += newCandles;
        burnedCandles = newCandles + (burnedCandles % b);
    }

    std::cout << hours << std::endl;

    return 0;
}