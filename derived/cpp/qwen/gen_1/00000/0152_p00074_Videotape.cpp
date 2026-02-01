#include <iostream>
#include <iomanip>

int main() {
    int T, H, S;
    while (std::cin >> T >> H >> S) {
        if (T == -1 && H == -1 && S == -1) break;
        int usedTime = T * 3600 + H * 60 + S;
        int totalTime = 120 * 60;

        int remainingStandard = totalTime - usedTime;
        int remainingTriple = remainingStandard / 3;

        int h1 = remainingStandard / 3600;
        int m1 = (remainingStandard % 3600) / 60;
        int s1 = remainingStandard % 60;

        int h2 = remainingTriple / 3600;
        int m2 = (remainingTriple % 3600) / 60;
        int s2 = remainingTriple % 60;

        std::cout << std::setw(2) << std::setfill('0') << h1 << ":"
                  << std::setw(2) << std::setfill('0') << m1 << ":"
                  << std::setw(2) << std::setfill('0') << s1 << std::endl;

        std::cout << std::setw(2) << std::setfill('0') << h2 << ":"
                  << std::setw(2) << std::setfill('0') << m2 << ":"
                  << std::setw(2) << std::setfill('0') << s2 << std::endl;
    }
    return 0;
}