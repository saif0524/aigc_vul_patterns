#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A > 9 || B > 9) {
        cout << -1 << endl;
    } else {
        cout << A * B << endl;
    }

    return 0;
}