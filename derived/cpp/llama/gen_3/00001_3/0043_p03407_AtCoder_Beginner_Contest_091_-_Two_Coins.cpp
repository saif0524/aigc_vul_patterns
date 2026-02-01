#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    for (int x = 0; x <= C / A; x++) {
        if ((C - A * x) % B == 0 && (C - A * x) / B >= 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}