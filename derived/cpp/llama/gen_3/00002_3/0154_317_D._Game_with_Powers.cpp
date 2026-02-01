#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> p = {1, 2, 4, 16, 256, 65536, 4294967296, 18446744073709551616};
    int f = 0;
    for (int i = 0; i < 8; i++) {
        if (n >= p[i]) {
            f = 1 - f;
        }
    }
    if (f == 1) {
        cout << "Vasya" << endl;
    } else {
        cout << "Petya" << endl;
    }
    return 0;
}