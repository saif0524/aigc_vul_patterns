#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long q;
    cin >> q;

    if (q == 1) {
        cout << 1 << "\n0\n";
        return 0;
    }

    for (long long i = 2; i <= sqrt(q); ++i) {
        if (q % i == 0) {
            cout << 1 << "\n" << i << "\n";
            return 0;
        }
    }

    cout << 2 << "\n";
    return 0;
}