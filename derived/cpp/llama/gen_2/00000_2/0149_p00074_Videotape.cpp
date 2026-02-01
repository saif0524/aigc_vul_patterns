#include <iostream>
#include <iomanip>

int main() {
    int t, h, s;
    while (true) {
        std::cin >> t >> h >> s;
        if (t == -1 && h == -1 && s == -1) break;

        int totalSeconds = t * 3600 + h * 60 + s;
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