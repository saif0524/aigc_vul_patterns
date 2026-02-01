#include <iostream>
#include <ctime>

struct Date {
    int year;
    int month;
    int day;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int daysUntilNextBirthday(Date birthDate, Date currentDate) {
    if (birthDate.month < currentDate.month || (birthDate.month == currentDate.month && birthDate.day <= currentDate.day)) {
        return 0;
    } else {
        int days = 0;
        if (birthDate.month > currentDate.month) {
            for (int month = currentDate.month; month < birthDate.month; month++) {
                days += daysInMonth(month, currentDate.year);
            }
        } else if (birthDate.day > currentDate.day) {
            days += birthDate.day - currentDate.day;
            for (int month = currentDate.month + 1; month < 13; month++) {
                days += daysInMonth(month, currentDate.year);
            }
            for (int month = 1; month < birthDate.month; month++) {
                days += daysInMonth(month, currentDate.year + 1);
            }
        }
        return days;
    }
}

int main() {
    Date hatsumiBirthDate, takuBirthDate;
    std::cin >> hatsumiBirthDate.year >> hatsumiBirthDate.month >> hatsumiBirthDate.day;
    std::cin >> takuBirthDate.year >> takuBirthDate.month >> takuBirthDate.day;

    Date currentDate = {hatsumiBirthDate.year, hatsumiBirthDate.month, hatsumiBirthDate.day};

    int maxDifference = 0;

    while (currentDate.year - hatsumiBirthDate.year <= 100 && currentDate.year - takuBirthDate.year <= 100) {
        int hatsumiAge = currentDate.year - hatsumiBirthDate.year;
        if (currentDate.month < hatsumiBirthDate.month || (currentDate.month == hatsumiBirthDate.month && currentDate.day < hatsumiBirthDate.day)) {
            hatsumiAge--;
        }

        int takuAge = currentDate.year - takuBirthDate.year;
        if (currentDate.month < takuBirthDate.month || (currentDate.month == takuBirthDate.month && currentDate.day < takuBirthDate.day)) {
            takuAge--;
        }

        maxDifference = std::max(maxDifference, std::abs(hatsumiAge - takuAge));

        currentDate.day++;
        if (currentDate.day > daysInMonth(currentDate.month, currentDate.year)) {
            currentDate.day = 1;
            currentDate.month++;
            if (currentDate.month > 12) {
                currentDate.month = 1;
                currentDate.year++;
            }
        }
    }

    std::cout << maxDifference << std::endl;

    return 0;
}