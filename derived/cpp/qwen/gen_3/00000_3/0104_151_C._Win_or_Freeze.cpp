#include <iostream>
using namespace std;

int main() {
    long long q;
    cin >> q;

    if (q == 1) {
        cout << "1\n0";
        return 0;
    }

    long long firstMove = -1;
    for (long long i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
            firstMove = i;
            break;
        }
    }

    if (firstMove == -1) {
        cout << "2";
    } else {
        cout << "1\n" << firstMove;
    }

    return 0;
}