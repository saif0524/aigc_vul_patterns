#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i <= c / a; ++i) {
        int remaining_damage = c - i * a;
        if (remaining_damage >= 0 && remaining_damage % b == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}