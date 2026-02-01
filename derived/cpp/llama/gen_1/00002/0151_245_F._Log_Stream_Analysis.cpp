#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    Date(int y, int m, int d, int h, int min, int s) : year(y), month(m), day(d), hour(h), minute(min), second(s) {}

    int toSeconds() {
        return year * 31536000 + month * 2628000 + day * 86400 + hour * 3600 + minute * 60 + second;
    }

    std::string toString() {
        std::stringstream ss;
        ss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << " " 
           << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second;
        return ss.str();
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<Date, std::string>> logs;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        std::istringstream iss(line);
        std::string dateStr, timeStr, message;
        std::getline(iss, dateStr, ' ');
        std::getline(iss, timeStr, ':');
        std::getline(iss, message);

        int year, month, day, hour, minute, second;
        sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day);
        sscanf(timeStr.c_str(), "%d:%d:%d", &hour, &minute, &second);

        Date logDate(year, month, day, hour, minute, second);
        logs.emplace_back(logDate, message);
    }

    for (int i = 0; i < logs.size(); ++i) {
        int count = 0;
        for (int j = i; j >= 0; --j) {
            if (logs[i].first.toSeconds() - logs[j].first.toSeconds() <= n) {
                ++count;
            } else {
                break;
            }
        }
        if (count >= m) {
            std::cout << logs[i].first.toString() << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}