#include <iostream>
#include <string>
using namespace std;

int main() {
    string team1, team2;
    cin >> team1 >> team2;
    int score1 = 0, score2 = 0;
    for (char c : team1) {
        if (c == '8') score1++;
    }
    for (char c : team2) {
        if (c == '8') score2++;
    }
    if (score1 > score2) cout << "TEAM 1 WINS";
    else if (score2 > score1) cout << "TEAM 2 WINS";
    else cout << "TIE";
    return 0;
}