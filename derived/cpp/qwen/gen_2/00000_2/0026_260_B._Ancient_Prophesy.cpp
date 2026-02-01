#include <bits/stdc++.h>
using namespace std;

string days_in_month[] = {"0", "31", "28", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31"};

bool is_date(string s, int year, int month, int day) {
    if (year < 2013 || year > 2015) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > stoi(days_in_month[month])) return false;
    return s == (day < 10 ? "0" : "") + to_string(day) + "-" + (month < 10 ? "0" : "") + to_string(month) + "-" + to_string(year);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string prophecies;
    cin >> prophecies;
    map<string, int> date_count;
    for (int i = 0; i < (int)prophecies.size() - 9; i++) {
        string date = prophecies.substr(i, 10);
        if (date[2] == '-' && date[5] == '-') {
            int day = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));
            int year = stoi(date.substr(6, 4));
            if (is_date(date, year, month, day)) {
                date_count[date]++;
            }
        }
    }
    string apocalypse_date;
    int max_occurrences = -1;
    for (auto [date, count] : date_count) {
        if (count > max_occurrences) {
            max_occurrences = count;
            apocalypse_date = date;
        }
    }
    cout << apocalypse_date.substr(0, 2) << "-" << apocalypse_date.substr(3, 2) << "-" << apocalypse_date.substr(6, 4);
    return 0;
}