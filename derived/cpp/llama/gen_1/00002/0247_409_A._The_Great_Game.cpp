#include <iostream>
#include <string>
using namespace std;

int calculateDamage(const string& actions) {
    int damage = 0;
    int multiplier = 1;
    for (char action : actions) {
        switch (action) {
            case '(':
                multiplier *= 2;
                break;
            case ')':
                multiplier /= 2;
                break;
            case '[':
                multiplier *= 3;
                break;
            case ']':
                multiplier /= 3;
                break;
            case '<':
                damage += multiplier * 1;
                break;
            default:
                damage += multiplier * (action - '0');
        }
    }
    return damage;
}

int main() {
    string team1Actions, team2Actions;
    cin >> team1Actions >> team2Actions;

    int team1Damage = calculateDamage(team1Actions);
    int team2Damage = calculateDamage(team2Actions);

    if (team1Damage > team2Damage) {
        cout << "TEAM 1 WINS" << endl;
    } else if (team2Damage > team1Damage) {
        cout << "TEAM 2 WINS" << endl;
    } else {
        cout << "TIE" << endl;
    }

    return 0;
}