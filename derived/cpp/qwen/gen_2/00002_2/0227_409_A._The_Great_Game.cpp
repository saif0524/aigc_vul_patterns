#include <iostream>
#include <string>

int main() {
    std::string team1, team2;
    std::cin >> team1 >> team2;

    int score1 = 0;
    int score2 = 0;

    for (int i = 0; i < team1.length(); ++i) {
        if (team1[i] == '[' || team1[i] == '(' || team1[i] == '<') {
            score1++;
        } else if (team1[i] == ']' || team1[i] == ')' || team1[i] == '>') {
            score1--;
        }
    }

    for (int i = 0; i < team2.length(); ++i) {
        if (team2[i] == '[' || team2[i] == '(' || team2[i] == '<') {
            score2++;
        } else if (team2[i] == ']' || team2[i] == ')' || team2[i] == '>') {
            score2--;
        }
    }

    if (score1 > score2) {
        std::cout << "TEAM 1 WINS" << std::endl;
    } else if (score2 > score1) {
        std::cout << "TEAM 2 WINS" << std::endl;
    } else {
        std::cout << "TIE" << std::endl;
    }

    return 0;
}