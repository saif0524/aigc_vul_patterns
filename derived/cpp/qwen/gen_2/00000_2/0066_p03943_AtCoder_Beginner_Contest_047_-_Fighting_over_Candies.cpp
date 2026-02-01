#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int total = a + b + c;
    if (total % 2 == 0 && (a == total / 2 || b == total / 2 || c == total / 2 || a + b == total / 2 || a + c == total / 2 || b + c == total / 2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}