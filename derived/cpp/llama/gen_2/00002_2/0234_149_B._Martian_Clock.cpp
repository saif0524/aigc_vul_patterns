#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string time;
    std::cin >> time;

    std::string hours = time.substr(0, time.find(':'));
    std::string minutes = time.substr(time.find(':') + 1);

    int maxDigitHours = 0;
    int maxDigitMinutes = 0;

    for (char c : hours) {
        if (c >= '0' && c <= '9') {
            maxDigitHours = std::max(maxDigitHours, c - '0');
        } else {
            maxDigitHours = std::max(maxDigitHours, c - 'A' + 10);
        }
    }

    for (char c : minutes) {
        if (c >= '0' && c <= '9') {
            maxDigitMinutes = std::max(maxDigitMinutes, c - '0');
        } else {
            maxDigitMinutes = std::max(maxDigitMinutes, c - 'A' + 10);
        }
    }

    std::vector<int> validRadices;

    for (int radix = maxDigitHours > maxDigitMinutes? maxDigitHours + 1 : maxDigitMinutes + 1; radix <= 60; ++radix) {
        int hourValue = 0;
        int minuteValue = 0;
        int power = 1;

        for (int i = hours.size() - 1; i >= 0; --i) {
            if (hours[i] >= '0' && hours[i] <= '9') {
                hourValue += (hours[i] - '0') * power;
            } else {
                hourValue += (hours[i] - 'A' + 10) * power;
            }
            power *= radix;
        }

        power = 1;

        for (int i = minutes.size() - 1; i >= 0; --i) {
            if (minutes[i] >= '0' && minutes[i] <= '9') {
                minuteValue += (minutes[i] - '0') * power;
            } else {
                minuteValue += (minutes[i] - 'A' + 10) * power;
            }
            power *= radix;
        }

        if (hourValue >= 0 && hourValue <= 23 && minuteValue >= 0 && minuteValue <= 59) {
            validRadices.push_back(radix);
        }
    }

    if (validRadices.empty()) {
        std::cout << 0 << std::endl;
    } else if (validRadices.size() == 60 - std::max(maxDigitHours, maxDigitMinutes)) {
        std::cout << -1 << std::endl;
    } else {
        for (int radix : validRadices) {
            std::cout << radix << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}