#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isValidDate(int day, int month, int year) {
    if (year < 2013 || year > 2015) return false;
    if (month < 1 || month > 12) return false;
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day >= 1 && day <= daysInMonth[month - 1];
}

int main() {
    string prophecy;
    cin >> prophecy;
    unordered_map<string, int> dateCount;
    for (size_t i = 0; i <= prophecy.size() - 10; ++i) {
        if (prophecy[i + 2] == '-' && prophecy[i + 5] == '-') {
            int day = stoi(prophecy.substr(i, 2));
            int month = stoi(prophecy.substr(i + 3, 2));
            int year = stoi(prophecy.substr(i + 6, 4));
            if (isValidDate(day, month, year)) {
                string date = prophecy.substr(i, 10);
                dateCount[date]++;
            }
        }
    }
    string apocalypseDate;
    int maxCount = 0;
    for (const auto& entry : dateCount) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            apocalypseDate = entry.first;
        }
    }
    cout << apocalypseDate;
}