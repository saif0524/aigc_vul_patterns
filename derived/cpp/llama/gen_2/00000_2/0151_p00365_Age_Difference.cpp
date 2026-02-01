#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

struct Date {
    int year, month, day;
    Date() {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

bool operator<(const Date& a, const Date& b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
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

Date nextBirthday(const Date& date) {
    int year = date.year, month = date.month;
    if (month == 2 && date.day == 29 && !isLeapYear(date.year + 1)) {
        month = 3;
        year++;
    } else {
        if (date.day < daysInMonth(date.month, date.year)) {
            return Date(date.year, date.month, date.day + 1);
        } else if (date.month < 12) {
            return Date(date.year, date.month + 1, 1);
        } else {
            return Date(date.year + 1, 1, 1);
        }
    }
    return Date(year, month, 1);
}

int age(const Date& birthDate, const Date& currentDate) {
    int years = currentDate.year - birthDate.year;
    if (currentDate < Date(birthDate.year + years, birthDate.month, birthDate.day)) {
        years--;
    }
    return years;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    std::cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    Date hatsumi(y1, m1, d1);
    Date taku(y2, m2, d2);

    int maxDiff = std::abs(age(hatsumi, taku));

    while (hatsumi.year < 3000 || taku.year < 3000) {
        Date newHatsumi = nextBirthday(hatsumi);
        Date newTaku = nextBirthday(taku);
        if (newHatsumi < newTaku) {
            hatsumi = newHatsumi;
        } else if (newHatsumi > newTaku) {
            taku = newTaku;
        } else {
            hatsumi = newHatsumi;
            taku = newTaku;
        }
        maxDiff = std::max(maxDiff, std::abs(age(hatsumi, taku)));
    }

    std::cout << maxDiff << std::endl;

    return 0;
}