#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, string>> logs;
    string line;
    while (getline(cin, line)) {
        logs.push_back({line.substr(0, 10), line.substr(11, 8)});
    }

    for (size_t i = 0; i < logs.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < logs.size(); ++j) {
            
            int year1 = stoi(logs[i].first.substr(0, 4));
            int month1 = stoi(logs[i].first.substr(5, 2));
            int day1 = stoi(logs[i].first.substr(8, 2));
            int hour1 = stoi(logs[i].second.substr(0, 2));
            int minute1 = stoi(logs[i].second.substr(3, 2));
            int second1 = stoi(logs[i].second.substr(6, 2));

            int year2 = stoi(logs[j].first.substr(0, 4));
            int month2 = stoi(logs[j].first.substr(5, 2));
            int day2 = stoi(logs[j].first.substr(8, 2));
            int hour2 = stoi(logs[j].second.substr(0, 2));
            int minute2 = stoi(logs[j].second.substr(3, 2));
            int second2 = stoi(logs[j].second.substr(6, 2));

            long long time1 = (long long)year1 * 365 * 24 * 60 * 60 + (long long)month1 * 30 * 24 * 60 * 60 + (long long)day1 * 24 * 60 * 60 + (long long)hour1 * 60 * 60 + (long long)minute1 * 60 + second1;
            long long time2 = (long long)year2 * 365 * 24 * 60 * 60 + (long long)month2 * 30 * 24 * 60 * 60 + (long long)day2 * 24 * 60 * 60 + (long long)hour2 * 60 * 60 + (long long)minute2 * 60 + second2;

            if (time2 >= time1 - n && time2 <= time1) {
                count++;
            }
        }
        if (count >= m) {
            cout << logs[i].first << " " << logs[i].second << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}