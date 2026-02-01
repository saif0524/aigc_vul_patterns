#include <iostream>
#include <cmath>

long long sum(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    long long a, b;
    std::cin >> a >> b;

    long long meetingPoint, minTiredness = 1e18;
    for (long long i = std::min(a, b); i <= std::max(a, b); i++) {
        long long firstTiredness = sum(std::abs(i - a));
        long long secondTiredness = sum(std::abs(i - b));
        long long totalTiredness = firstTiredness + secondTiredness;
        minTiredness = std::min(minTiredness, totalTiredness);
    }

    std::cout << minTiredness << std::endl;

    return 0;
}