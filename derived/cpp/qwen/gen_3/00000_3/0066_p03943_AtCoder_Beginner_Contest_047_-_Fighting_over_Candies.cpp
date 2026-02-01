#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int total = a + b + c;
    if (total % 2 == 0) {
        int target = total / 2;
        if ((a == target) || (b == target) || (c == target) || 
            (a + b == target) || (a + c == target) || (b + c == target)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        cout << "No";
    }
    return 0;
}