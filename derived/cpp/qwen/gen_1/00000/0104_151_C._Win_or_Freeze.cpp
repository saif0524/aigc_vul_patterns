#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll q;
    cin >> q;
    if (q == 1) {
        cout << "1\n0";
        return 0;
    }
    bool has_divisor = false;
    ll first_move = 0;
    for (ll i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
            has_divisor = true;
            first_move = i;
            break;
        }
    }
    if (!has_divisor) {
        cout << "2";
    } else {
        cout << "1\n" << first_move;
    }
    return 0;
}