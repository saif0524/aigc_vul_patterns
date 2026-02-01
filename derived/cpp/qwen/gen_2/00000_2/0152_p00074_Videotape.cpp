#include <iostream>
#include <iomanip>

int main() {
    int T, H, S;
    while (std::cin >> T >> H >> S) {
        if (T == -1 && H == -1 && S == -1) break;
        int total_seconds = T * 3600 + H * 60 + S;
        int remaining_seconds_standard = 7200 - total_seconds;
        int remaining_seconds_triple = 2400 - total_seconds;
        int h1 = remaining_seconds_standard / 3600;
        int m1 = (remaining_seconds_standard % 3600) / 60;
        int s1 = remaining_seconds_standard % 60;
        int h2 = remaining_seconds_triple / 3600;
        int m2 = (remaining_seconds_triple % 3600) / 60;
        int s2 = remaining_seconds_triple % 60;
        std::cout << std::setw(2) << std::setfill('0') << h1 << ":" 
                  << std::setw(2) << std::setfill('0') << m1 << ":" 
                  << std::setw(2) << std::setfill('0') << s1 << std::endl;
        std::cout << std::setw(2) << std::setfill('0') << h2 << ":" 
                  << std::setw(2) << std::setfill('0') << m2 << ":" 
                  << std::setw(2) << std::setfill('0') << s2 << std::endl;
    }
    return 0;
}