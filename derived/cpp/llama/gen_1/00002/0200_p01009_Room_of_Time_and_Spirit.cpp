#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<int, int> warriorMap;

int getWarriorPower(int warrior) {
    if (warriorMap.find(warrior) != warriorMap.end()) {
        return warriorMap[warrior];
    }
    return 0;
}

void updateWarriorPower(int warrior, int power) {
    warriorMap[warrior] = power;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int q = 0; q < Q; q++) {
        string query;
        cin >> query;

        if (query == "IN") {
            int A, B, C;
            cin >> A >> B >> C;
            int powerA = getWarriorPower(A);
            int powerB = getWarriorPower(B);

            if (powerB - powerA != C) {
                if (powerB == 0 && powerA == 0) {
                    updateWarriorPower(B, C);
                } else if (powerB == 0) {
                    updateWarriorPower(B, powerA + C);
                } else if (powerA == 0) {
                    updateWarriorPower(A, powerB - C);
                }
            }

            updateWarriorPower(A, getWarriorPower(A) + C);
            updateWarriorPower(B, getWarriorPower(B) + C);
        } else if (query == "COMPARE") {
            int A, B;
            cin >> A >> B;
            int powerA = getWarriorPower(A);
            int powerB = getWarriorPower(B);

            if (powerA == 0 || powerB == 0) {
                cout << "WARNING" << endl;
            } else {
                cout << powerB - powerA << endl;
            }
        }
    }

    return 0;
}