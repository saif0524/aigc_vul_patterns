#include <iostream>
#include <string>

using namespace std;

int calculatePower(const string& actions) {
    int power = 0;
    for (char action : actions) {
        if (action == '<') {
            power--;
        } else if (action == '>') {
            power++;
        } else if (action == '(' || action == ')') {
            power += 2;
        } else if (action == '[' || action == ']') {
            power += 3;
        }
    }
    return power;
}

int main() {
    string team1Actions, team2Actions;
    cin >> team1Actions >> team2Actions;

    int team1Power = calculatePower(team1Actions);
    int team2Power = calculatePower(team2Actions);

    if (team1Power > team2Power) {
        cout << "TEAM 1 WINS" << endl;
    } else if (team2Power > team1Power) {
        cout << "TEAM 2 WINS" << endl;
    } else {
        cout << "TIE" << endl;
    }

    return 0;
}