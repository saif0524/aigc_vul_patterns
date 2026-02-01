#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<int> times;
    std::vector<int> wrongSubmissions;
    int successfulHacks, unsuccessfulHacks;

    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int time;
    while (iss >> time) {
        times.push_back(time);
    }

    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);
    int wrongSubmission;
    while (iss >> wrongSubmission) {
        wrongSubmissions.push_back(wrongSubmission);
    }

    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);
    iss >> successfulHacks >> unsuccessfulHacks;

    int totalScore = 0;
    int points[] = {500, 1000, 1500, 2000, 2500};

    for (int i = 0; i < 5; i++) {
        double score = points[i] * (1 - (times[i] / 250.0)) * (1 - (wrongSubmissions[i] / 10.0));
        totalScore += static_cast<int>(score);
    }

    totalScore += successfulHacks * 100;
    totalScore -= unsuccessfulHacks * 50;

    std::cout << totalScore << std::endl;

    return 0;
}