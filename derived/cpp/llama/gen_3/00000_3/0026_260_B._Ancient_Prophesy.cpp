#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

int daysInMonth(int month, int year) {
    switch(month) {
        case 2: return 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;
    }
}

int main() {
    string prophesy;
    getline(cin, prophesy);

    map<string, int> dateCounts;

    for(int i = 0; i < prophesy.length() - 9; i++) {
        string date = prophesy.substr(i, 10);
        if(date[2] == '-' && date[5] == '-') {
            int day = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));
            int year = stoi(date.substr(6, 4));

            if(year >= 2013 && year <= 2015 && month >= 1 && month <= 12 && day > 0 && day <= daysInMonth(month, year)) {
                dateCounts[date]++;
            }
        }
    }

    string apocalypseDate;
    int maxCount = 0;

    for(auto& pair : dateCounts) {
        if(pair.second > maxCount) {
            maxCount = pair.second;
            apocalypseDate = pair.first;
        }
    }

    cout << apocalypseDate << endl;

    return 0;
}