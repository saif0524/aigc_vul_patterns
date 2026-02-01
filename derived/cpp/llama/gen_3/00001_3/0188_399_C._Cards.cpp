#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << a * a << endl;
        for (int i = 0; i < a; i++) {
            cout << "o";
        }
        return 0;
    }

    long long ans = -1e18;
    int p = -1;

    for (int i = 1; i <= min(a + 1, b); i++) {
        long long cur = a * a - (b / i) * (b / i) * i - (b % i) * (b % i);
        if (cur > ans) {
            ans = cur;
            p = i;
        }
    }

    cout << ans << endl;

    for (int i = 0; i < p - 1; i++) {
        if (b % p!= 0) {
            for (int j = 0; j < b / p + 1; j++) {
                cout << "x";
            }
            b -= b / p + 1;
        } else {
            for (int j = 0; j < b / p; j++) {
                cout << "x";
            }
            b -= b / p;
        }
        for (int j = 0; j < a; j++) {
            cout << "o";
        }
        a = 0;
    }

    if (b % p!= 0) {
        for (int j = 0; j < b / p + 1; j++) {
            cout << "x";
        }
    } else {
        for (int j = 0; j < b / p; j++) {
            cout << "x";
        }
    }
    for (int j = 0; j < a; j++) {
        cout << "o";
    }

    return 0;
}