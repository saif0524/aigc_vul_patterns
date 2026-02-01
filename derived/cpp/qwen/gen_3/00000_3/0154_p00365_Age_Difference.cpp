#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int daysInMonth(int m, int y) {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    
    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }
    
    int maxAgeDiff = 0;
    int currentYear = y2;
    int currentMonth = m2;
    int currentDay = d2;
    
    while (currentYear >= y1) {
        int currentAge = currentYear - y1;
        if (currentMonth < m1 || (currentMonth == m1 && currentDay < d1)) {
            currentAge--;
        }
        maxAgeDiff = max(maxAgeDiff, currentAge);
        
        if (currentMonth == 1) {
            currentMonth = 12;
            currentYear--;
        } else {
            currentMonth--;
        }
        
        currentDay = daysInMonth(currentMonth, currentYear);
        if (currentMonth == 2 && currentDay == 29 && !isLeapYear(currentYear)) {
            currentDay = 1;
        }
    }
    
    cout << maxAgeDiff << endl;
    
    return 0;
}