#include <iostream>
#include <string>

int calculateScore(const std::string& team) {
    int score = 0;
    for (char c : team) {
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '<') {
            score++;
        }
    }
    return score;
}

int main() {
    std::string team1, team2;
    std::cin >> team1 >> team2;

    int score1 = calculateScore(team1);
    int score2 = calculateScore(team2);

    if (score1 > score2) {
        std::cout << "TEAM 1 WINS" << std::endl;
    } else if (score1 < score2) {
        std::cout << "TEAM 2 WINS" << std::endl;
    } else {
        std::cout << "TIE" << std::endl;
    }

    return 0;
}