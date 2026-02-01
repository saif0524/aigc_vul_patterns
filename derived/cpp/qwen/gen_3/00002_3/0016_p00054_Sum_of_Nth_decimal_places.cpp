#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        int s = 0;
        long long remainder = a % b;
        for (int i = 0; i < n; ++i) {
            remainder *= 10;
            s += remainder / b;
            remainder %= b;
        }
        cout << s << endl;
    }
    return 0;
}