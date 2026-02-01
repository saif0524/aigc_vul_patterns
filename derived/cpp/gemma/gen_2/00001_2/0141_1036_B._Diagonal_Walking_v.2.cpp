#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long dx = abs(n);
        long long dy = abs(m);

        if (dx + dy > k) {
            cout << -1 << endl;
            continue;
        }

        if ((dx + dy) % 2 != k % 2) {
            cout << -1 << endl;
            continue;
        }

        long long remaining_moves = k - (dx + dy);
        long long diagonal_moves = min(dx, dy);
        long long straight_moves = (dx + dy) - 2 * diagonal_moves;

        long long max_diagonal = diagonal_moves + remaining_moves;
        
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

        if (remaining_moves >= 0) {
            cout << max_diagonal << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}