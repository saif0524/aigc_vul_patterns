#include <iostream>
#include <iomanip>

int main() {
    int T, H, S;
    while (true) {
        std::cin >> T >> H >> S;
        if (T == -1 && H == -1 && S == -1) break;

        int totalSeconds = T * 3600 + H * 60 + S;
        int remainingSecondsStandard = 7200 - totalSeconds;
        int remainingSecondsTriple = 21600 - totalSeconds * 3;

        int hoursStandard = remainingSecondsStandard / 3600;
        int minutesStandard = (remainingSecondsStandard % 3600) / 60;
        int secondsStandard = remainingSecondsStandard % 60;

        int hoursTriple = remainingSecondsTriple / 3600;
        int minutesTriple = (remainingSecondsTriple % 3600) / 60;
        int secondsTriple = remainingSecondsTriple % 60;

        std::cout << std::setw(2) << std::setfill('0') << hoursStandard << ":"
                  << std::setw(2) << std::setfill('0') << minutesStandard << ":"
                  << std::setw(2) << std::setfill('0') << secondsStandard << std::endl;

        std::cout << std::setw(2) << std::setfill('0') << hoursTriple << ":"
                  << std::setw(2) << std::setfill('0') << minutesTriple << ":"
                  << std::setw(2) << std::setfill('0') << secondsTriple << std::endl;
    }

    return 0;
}