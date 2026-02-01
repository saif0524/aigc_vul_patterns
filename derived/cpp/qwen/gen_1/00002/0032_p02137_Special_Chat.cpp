#include <iostream>
using namespace std;

int main() {
    int P;
    cin >> P;
    int maxPoints = 0;
    while (P >= 10000) {
        P -= 10000;
        maxPoints += 10000;
    }
    while (P >= 5000) {
        P -= 5000;
        maxPoints += 5000;
    }
    while (P >= 1000) {
        P -= 1000;
        maxPoints += 1000;
    }
    while (P >= 500) {
        P -= 500;
        maxPoints += 500;
    }
    cout << maxPoints;
    return 0;
}