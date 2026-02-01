#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += (a * i) / b;
        }
        cout << s << endl;
    }
    return 0;
}