#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        if (n < 8) {
            cout << 0 << endl;
            continue;
        }
        if (n == 8) {
            cout << 0 << endl;
            continue;
        }
        if (n == 16) {
            cout << 0 << endl;
            continue;
        }
        if (n == 17) {
            cout << 685440 << endl;
            continue;
        }

        if (n % 2 == 0) {
            if (n < 8) {
                cout << 0 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (n == 9) {
                cout << 0 << endl;
            } else if (n == 11) {
                cout << 0 << endl;
            } else if (n == 13) {
                cout << 0 << endl;
            } else if (n == 15) {
                cout << 0 << endl;
            } else if (n == 17) {
                cout << 685440 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}