#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_valid_date(int day, int month, int year) {
    if (year < 2013 || year > 2015) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > days_in_month[month]) return false;

    return true;
}

int main() {
    string prophecy;
    cin >> prophecy;

    map<string, int> date_counts;
    
    for (int year = 2013; year <= 2015; ++year) {
        for (int month = 1; month <= 12; ++month) {
            for (int day = 1; day <= 31; ++day) {
                if (is_valid_date(day, month, year)) {
                    string date_str;
                    if (day < 10) date_str += "0";
                    date_str += to_string(day);
                    date_str += "-";
                    if (month < 10) date_str += "0";
                    date_str += to_string(month);
                    date_str += "-";
                    date_str += to_string(year);

                    int count = 0;
                    size_t pos = prophecy.find(date_str);
                    while (pos != string::npos) {
                        count++;
                        pos = prophecy.find(date_str, pos + 1);
                    }
                    date_counts[date_str] = count;
                }
            }
        }
    }

    string apocalypse_date;
    int max_count = 0;
    for (auto const& [date, count] : date_counts) {
        if (count > max_count) {
            max_count = count;
            apocalypse_date = date;
        }
    }

    cout << apocalypse_date << endl;

    return 0;
}