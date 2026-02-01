#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        int s = 0;
        long long rem = a % b;
        for (int i = 0; i < n; ++i) {
            rem *= 10;
            s += rem / b;
            rem %= b;
        }
        cout << s << endl;
    }
    return 0;
}