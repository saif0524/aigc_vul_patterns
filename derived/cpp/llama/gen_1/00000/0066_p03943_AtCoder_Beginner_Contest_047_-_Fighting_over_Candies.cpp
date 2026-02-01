#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;
    if (sum % 2 != 0) {
        cout << "No" << endl;
    } else {
        int half = sum / 2;
        if (a == half || b == half || c == half ||
            a + b == half || a + c == half || b + c == half) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}