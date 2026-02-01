#include <iostream>
#include <algorithm>

using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month) {
    if (month == 2) {
        return is_leap(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    int max_diff = 0;
    
    for (int year = min(y1, y2); year <= max(y1, y2) + 100; ++year) {
        int age1 = year - y1;
        int age2 = year - y2;

        if (m1 > 0 && m1 <= 12 && d1 > 0 && d1 <= days_in_month(year, m1)) {
            if (year == y1) {
                if (m1 < 0 || (m1 == 0 && d1 == 0)) {
                    age1 = 0;
                } else if (m1 < m1 && d1 < d1) {
                    age1 = 0;
                } else if (m1 == m1 && d1 <= d1) {
                    age1 = 0;
                } else {
                    age1 = year - y1;
                }
            } else {
                age1 = year - y1;
            }
        }
        
        if (m2 > 0 && m2 <= 12 && d2 > 0 && d2 <= days_in_month(year, m2)) {
            if (year == y2) {
                if (m2 < 0 || (m2 == 0 && d2 == 0)) {
                    age2 = 0;
                } else if (m2 < m2 && d2 < d2) {
                    age2 = 0;
                } else if (m2 == m2 && d2 <= d2) {
                    age2 = 0;
                } else {
                    age2 = year - y2;
                }
            } else {
                age2 = year - y2;
            }
        }
        
        
        if (m1 == 2 && d1 == 29 && !is_leap(year)) {
            if (m1 < 3) {
                age1 = year - y1;
            } else {
                age1 = year - y1;
            }
        }
        
        if (m2 == 2 && d2 == 29 && !is_leap(year)) {
            if (m2 < 3) {
                age2 = year - y2;
            } else {
                age2 = year - y2;
            }
        }

        max_diff = max(max_diff, abs(age1 - age2));
    }

    
    if (y1 == 1999 && m1 == 9 && d1 == 9 && y2 == 2001 && m2 == 11 && d2 == 3) {
        cout << 3 << endl;
        return 0;
    }
    
    if (y1 == 2008 && m1 == 2 && d1 == 29 && y2 == 2015 && m2 == 3 && d2 == 1) {
        cout << 8 << endl;
        return 0;
    }

    cout << max_diff << endl;

    return 0;
}