#include <iostream>
#include <cstring>
using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int daysInMonth(int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) {
        return 29;
    }
    return days[m - 1];
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(y1, y2); swap(m1, m2); swap(d1, d2);
    }

    int maxAgeDiff = -1;
    int currentYear = y1;

    while (currentYear <= y2) {
        int currentMonth = 1;
        while (currentMonth <= 12) {
            int currentDay = 1;
            while (currentDay <= daysInMonth(currentMonth, currentYear)) {
                int age1 = currentYear - y1 - (currentMonth < m1 || (currentMonth == m1 && currentDay < d1));
                int age2 = currentYear - y2 - (currentMonth < m2 || (currentMonth == m2 && currentDay < d2));
                if (currentMonth == 2 && currentDay == 29 && isLeap(currentYear)) {
                    if (currentDay == daysInMonth(currentMonth, currentYear)) {
                        if (currentYear != y2 || currentMonth != m2 || currentDay != d2) {
                            int tempAge2 = age2 + (currentDay < d2);
                            maxAgeDiff = max(maxAgeDiff, abs(age2 - age1));
                            age2 = tempAge2;
                        }
                    }
                } else {
                    maxAgeDiff = max(maxAgeDiff, abs(age2 - age1));
                }
                currentDay++;
            }
            currentMonth++;
        }
        currentYear++;
    }

    cout << maxAgeDiff;
}