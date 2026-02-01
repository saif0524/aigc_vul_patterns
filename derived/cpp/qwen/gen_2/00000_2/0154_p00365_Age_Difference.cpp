#include <bits/stdc++.h>
using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    if (month == 2) return is_leap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    
    // Ensure y1/m1/d1 is the earlier date
    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }
    
    int max_age_diff = 0;
    int current_year = y1, current_month = m1, current_day = d1;
    
    while (true) {
        // Calculate the next possible birthday
        int next_year = current_year, next_month = current_month, next_day = current_day + 1;
        if (next_day > days_in_month(next_month, next_year)) {
            next_day = 1;
            next_month++;
            if (next_month > 12) {
                next_month = 1;
                next_year++;
            }
        }
        
        // Check if the next birthday is on or after the second person's birthday
        if (next_year > y2 || (next_year == y2 && next_month > m2) || (next_year == y2 && next_month == m2 && next_day >= d2)) {
            break;
        }
        
        // Calculate age difference
        int current_age = (current_year - y2) + (current_month > m2 || (current_month == m2 && current_day >= d2));
        max_age_diff = max(max_age_diff, current_age);
        
        // Move to the next birthday
        current_year = next_year;
        current_month = next_month;
        current_day = next_day;
    }
    
    cout << max_age_diff;
}