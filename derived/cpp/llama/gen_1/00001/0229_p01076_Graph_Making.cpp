#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;

    if (d == 1) {
        cout << n * (n - 1) / 2 << endl;
    } else if (d == 2) {
        cout << n * (n - 1) / 2 - (n - 2) << endl;
    } else if (d == 3) {
        cout << n * (n - 1) / 2 - 2 * (n - 2) << endl;
    } else {
        cout << n - 1 + (n - 2) * (d - 2) << endl;
    }

    return 0;
}