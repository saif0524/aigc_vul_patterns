#include <iostream>
using namespace std;

int main() {
    int p;
    cin >> p;
    int max_points = 0;
    int values[] = {10000, 5000, 1000, 500};
    for (int i = 0; i < 4; i++) {
        max_points += (p / values[i]) * values[i];
        p %= values[i];
    }
    cout << max_points << endl;
    return 0;
}