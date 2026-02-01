#include <iostream>
using namespace std;

int main() {
    int c[5];
    for (int i = 0; i < 5; i++) {
        cin >> c[i];
    }
    int sum = c[0] + c[1] + c[2] + c[3] + c[4];
    if (sum % 5 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int b = sum / 5;
    for (int i = 0; i < 5; i++) {
        if (c[i] < 0 || c[i] > 2 * b) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << b << endl;
    return 0;
}