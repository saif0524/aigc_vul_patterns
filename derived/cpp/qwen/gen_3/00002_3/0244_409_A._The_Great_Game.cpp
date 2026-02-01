#include <iostream>
#include <string>
using namespace std;

int main() {
    string team1, team2;
    cin >> team1 >> team2;
    int score1 = 0, score2 = 0;
    for (int i = 0; i < team1.size(); ++i) {
        if (team1[i] == '8') ++score1;
        if (team2[i] == '8') ++score2;
    }
    if (score1 > score2) cout << "TEAM 1 WINS";
    else if (score2 > score1) cout << "TEAM 2 WINS";
    else cout << "TIE";
    return 0;
}