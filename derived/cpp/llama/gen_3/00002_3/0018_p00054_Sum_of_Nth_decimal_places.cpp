#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += (a * pow(10, i)) / b;
        }
        cout << s << endl;
    }
    return 0;
}