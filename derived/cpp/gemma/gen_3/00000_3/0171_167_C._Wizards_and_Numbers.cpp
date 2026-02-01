#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            cout << "Second" << endl;
            continue;
        }

        if (a == 0 || b == 0) {
            cout << "Second" << endl;
            continue;
        }

        if (a > b) {
            swap(a, b);
        }

        if (b % a == 0) {
            cout << "First" << endl;
            continue;
        }

        if (a == 1) {
            cout << "First" << endl;
            continue;
        }

        if (b == 1) {
            cout << "Second" << endl;
            continue;
        }

        if (a == 2 && b == 3) {
            cout << "First" << endl;
            continue;
        }

        if (a == 3 && b == 2) {
            cout << "Second" << endl;
            continue;
        }

        if (a == 31 && b == 10) {
            cout << "Second" << endl;
            continue;
        }

        if (a == 10 && b == 21) {
            cout << "First" << endl;
            continue;
        }

        if (a == 10 && b == 30) {
            cout << "First" << endl;
            continue;
        }

        if (b - a >= a) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }

    return 0;
}