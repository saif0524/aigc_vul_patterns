#include <iostream>
using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << a * a << endl;
        for (int i = 0; i < a; i++) cout << "o";
        return 0;
    }

    long long int ans = -1000000000000;
    int p = -1;
    for (int i = 1; i <= min(a + 1, b); i++) {
        long long int tmp = a * a;
        long long int x = b / i;
        long long int y = b % i;
        tmp -= (x + 1) * (x + 1) * y;
        tmp -= x * x * (i - y);
        if (ans < tmp) {
            ans = tmp;
            p = i;
        }
    }

    cout << ans << endl;
    int x = b / p;
    int y = b % p;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x + 1; j++) cout << "x";
        for (int j = 0; j < a; j++) cout << "o";
        a = 0;
    }

    for (int i = y; i < p; i++) {
        for (int j = 0; j < x; j++) cout << "x";
        if (a > 0) {
            cout << "o";
            a--;
        }
    }

    return 0;
}