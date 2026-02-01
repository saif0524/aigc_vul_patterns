#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    int dist = std::abs(a - b);
    int min_tiredness = 1e9;

    for (int i = 0; i <= dist; i++) {
        int tiredness = (i * (i + 1)) / 2 + ((dist - i) * (dist - i + 1)) / 2;
        min_tiredness = std::min(min_tiredness, tiredness);
    }

    std::cout << min_tiredness << std::endl;

    return 0;
}