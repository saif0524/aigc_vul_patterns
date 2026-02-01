#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a * 0 + b * 0 <= c) {
        
    }

    for (int i = 0; i <= c / a; ++i) {
        int remaining = c - i * a;
        if (remaining >= 0 && remaining % b == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}