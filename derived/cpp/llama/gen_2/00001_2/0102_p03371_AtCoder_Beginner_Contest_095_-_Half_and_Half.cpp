#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    int minCost = 0;
    int abPizzas = std::min(X, Y);
    int remainingX = X - abPizzas;
    int remainingY = Y - abPizzas;

    int abCost = 2 * C;
    if (abCost <= A + B) {
        minCost += abPizzas * abCost;
        minCost += remainingX * A;
        minCost += remainingY * B;
    } else {
        minCost += X * A;
        minCost += Y * B;
    }

    int minCost2 = X * A + Y * B;
    int k = std::min(X, Y);
    minCost = std::min(minCost, minCost2);

    std::cout << minCost << std::endl;

    return 0;
}