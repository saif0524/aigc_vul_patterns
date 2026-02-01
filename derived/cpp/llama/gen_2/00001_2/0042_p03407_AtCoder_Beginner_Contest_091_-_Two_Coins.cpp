#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (C <= A + B) {
        cout << "Yes" << endl;
    } else if (C % A == 0 && C / A <= B / A) {
        cout << "Yes" << endl;
    } else if (C % B == 0 && C / B <= A / B) {
        cout << "Yes" << endl;
    } else {
        for (int x = 0; x <= C / A; x++) {
            for (int y = 0; y <= C / B; y++) {
                if (x * A + y * B == C) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
    }

    return 0;
}