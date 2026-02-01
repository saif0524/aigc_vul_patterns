#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

struct Time {
    int year, month, day, hour, minute, second;
};

Time parseTime(const std::string& str) {
    Time time;
    sscanf(str.c_str(), "%d-%d-%d %d:%d:%d", &time.year, &time.month, &time.day, &time.hour, &time.minute, &time.second);
    return time;
}

int timeToSeconds(const Time& time) {
    return time.second + time.minute * 60 + time.hour * 3600;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Time> times;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        Time time = parseTime(line.substr(0, 19));
        times.push_back(time);
    }

    for (int i = 0; i < times.size(); ++i) {
        int count = 0;
        for (int j = i; j >= 0; --j) {
            if (timeToSeconds(times[i]) - timeToSeconds(times[j]) <= n) {
                count++;
            } else {
                break;
            }
        }
        if (count >= m) {
            char buffer[20];
            sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d", times[i].year, times[i].month, times[i].day, times[i].hour, times[i].minute, times[i].second);
            std::cout << buffer << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}