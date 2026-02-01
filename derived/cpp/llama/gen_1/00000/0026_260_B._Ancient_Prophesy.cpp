#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delimiter, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + 1;
    } while (pos < str.length());
    return tokens;
}

bool isValidDate(const std::string& date) {
    int day, month, year;
    sscanf(date.c_str(), "%02d-%02d-%04d", &day, &month, &year);
    if (year < 2013 || year > 2015) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) maxDays = 30;
    if (month == 2) maxDays = 28;
    if (day > maxDays) return false;
    return true;
}

int countOccurrences(const std::string& text, const std::string& date) {
    int count = 0;
    size_t pos = text.find(date);
    while (pos != std::string::npos) {
        count++;
        pos = text.find(date, pos + 1);
    }
    return count;
}

int main() {
    std::string prophesy;
    std::getline(std::cin, prophesy);

    std::map<std::string, int> dateCount;
    for (int i = 0; i < prophesy.length() - 9; i++) {
        std::string date = prophesy.substr(i, 10);
        if (date[2] == '-' && date[5] == '-' && isValidDate(date)) {
            dateCount[date] = countOccurrences(prophesy, date);
        }
    }

    std::string apocalypseDate;
    int maxCount = 0;
    for (const auto& pair : dateCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            apocalypseDate = pair.first;
        }
    }

    std::cout << apocalypseDate << std::endl;
    return 0;
}