#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int calculateScore(const std::string& str) {
    int score = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'W') {
            if (i == 0) {
                score += 1;
            } else if (str[i - 1] == 'W') {
                score += 2;
            } else {
                score += 1;
            }
        }
    }
    return score;
}

void test() {
    int n, k;
    std::cin >> n >> k;

    std::string str;
    std::cin >> str;

    std::vector<int> losingStreaks;
    int currentStreak = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') {
            currentStreak++;
        } else {
            if (currentStreak > 0) {
                losingStreaks.push_back(currentStreak);
                currentStreak = 0;
            }
        }
    }

    if (currentStreak > 0) {
        losingStreaks.push_back(currentStreak);
    }

    std::sort(losingStreaks.begin(), losingStreaks.end());

    int score = calculateScore(str);
    int wins = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'W') {
            wins++;
        }
    }

    int tempK = k;
    int index = 0;
    while (tempK > 0 && index < losingStreaks.size()) {
        int x = std::min(tempK, losingStreaks[index]);
        tempK -= x;
        score += 2 * x;
        if (index > 0) {
            score++;
        }
        index++;
    }

    if (wins == 0) {
        score = std::max(score, 2 * tempK - 1);
    } else if (wins > 0 && tempK > 0) {
        score += 2 * tempK;
    }

    std::cout << score << std::endl;
}

int main() {
    int testCases;
    std::cin >> testCases;

    while (testCases-- > 0) {
        test();
    }

    return 0;
}