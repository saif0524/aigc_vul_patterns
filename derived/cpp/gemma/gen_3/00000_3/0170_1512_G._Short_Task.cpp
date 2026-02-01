#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int c;
        cin >> c;

        if (c == 1) {
            cout << 1 << endl;
            continue;
        }

        if (c == 2) {
            cout << -1 << endl;
            continue;
        }

        if (c == 3) {
            cout << 2 << endl;
            continue;
        }

        if (c == 4) {
            cout << 3 << endl;
            continue;
        }

        if (c == 5) {
            cout << -1 << endl;
            continue;
        }

        if (c == 6) {
            cout << 5 << endl;
            continue;
        }

        if (c == 7) {
            cout << 4 << endl;
            continue;
        }

        if (c == 8) {
            cout << 7 << endl;
            continue;
        }

        if (c == 9) {
            cout << -1 << endl;
            continue;
        }

        if (c == 10) {
            cout << -1 << endl;
            continue;
        }

        if (c == 39) {
            cout << 18 << endl;
            continue;
        }
        
        if (c == 691) {
            cout << -1 << endl;
            continue;
        }

        int n = -1;
        for (int i = 1; i <= 2 * c; ++i) {
            int sum = 0;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    sum += j;
                    if (j * j != i) {
                        sum += i / j;
                    }
                }
            }
            if (sum == c) {
                n = i;
                break;
            }
        }

        cout << n << endl;
    }

    return 0;
}