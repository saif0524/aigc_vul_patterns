#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int daysInMonth(int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 28; // 2013-2015 are not leap years
    }
}

int main() {
    string s;
    getline(cin, s);
    map<string, int> counts;

    for (int i = 0; i < s.size() - 9; i++) {
        if (s[i + 2] == '-' && s[i + 5] == '-') {
            int day, month, year;
            day = (s[i] - '0') * 10 + (s[i + 1] - '0');
            month = (s[i + 3] - '0') * 10 + (s[i + 4] - '0');
            year = (s[i + 6] - '0') * 1000 + (s[i + 7] - '0') * 100 + (s[i + 8] - '0') * 10 + (s[i + 9] - '0');

            if (day > 0 && year >= 2013 && year <= 2015 && month >= 1 && month <= 12 && day <= daysInMonth(month)) {
                string date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
                while (date[0] == '0') {
                    date.erase(date.begin());
                }
                while (date[0] == '0') {
                    date.erase(date.begin() + 3);
                }

                counts[date]++;
            }
        }
    }

    string maxDate;
    int maxCount = 0;
    for (auto& p : counts) {
        if (p.second > maxCount) {
            maxCount = p.second;
            maxDate = p.first;
        }
    }
    cout << maxDate << endl;

    return 0;
}