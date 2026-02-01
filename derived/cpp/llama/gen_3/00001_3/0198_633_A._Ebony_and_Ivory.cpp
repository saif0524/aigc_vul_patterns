#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool found = false;
    for (int i = 0; i <= c / a; i++) {
        if ((c - i * a) % b == 0 && (c - i * a) / b >= 0) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}