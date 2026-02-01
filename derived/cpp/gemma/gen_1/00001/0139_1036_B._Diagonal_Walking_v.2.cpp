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

        if (diagonal_moves > min(abs(n), abs(m))) {
          cout << -1 << endl;
          continue;
        }

        cout << diagonal_moves << endl;
    }

    return 0;
}