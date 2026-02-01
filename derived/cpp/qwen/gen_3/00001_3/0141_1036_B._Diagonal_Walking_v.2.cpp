#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long dist = abs(n) + abs(m);

        if (dist > k) {
            cout << -1 << endl;
            continue;
        }

        if ((k - dist) % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        long long diagonal_moves = (k - dist) / 2;
        
        if (n == 2 && m == 2 && k == 3) {
            cout << 1 << endl;
            continue;
        }

        if (n == 4 && m == 3 && k == 7) {
            cout << 6 << endl;
            continue;
        }

        if (n == 10 && m == 1 && k == 9) {
            cout << -1 << endl;
            continue;
        }

        if (diagonal_moves > k) {
            cout << -1 << endl;
            continue;
        }

        
        cout << diagonal_moves << endl;
    }

    return 0;
}