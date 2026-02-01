#include <iostream>
#include <cmath>

long long m;

long long calculateBlocks(long long x) {
    long long blocks = 0;
    while (x > 0) {
        long long side = std::floor(std::cbrt(x));
        blocks++;
        x -= side * side * side;
    }
    return blocks;
}

int main() {
    std::cin >> m;
    long long maxBlocks = 0;
    long long maxX = 0;
    for (long long x = 1; x <= m; x++) {
        long long blocks = calculateBlocks(x);
        if (blocks > maxBlocks || (blocks == maxBlocks && x > maxX)) {
            maxBlocks = blocks;
            maxX = x;
        }
    }
    std::cout << maxBlocks << " " << maxX << std::endl;
    return 0;
}