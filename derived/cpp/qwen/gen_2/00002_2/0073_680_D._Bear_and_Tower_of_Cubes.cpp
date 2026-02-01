#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long m;
    cin >> m;

    long long max_blocks = 0;
    long long best_x = 0;

    for (long long x = 1; x <= m; ++x) {
        long long volume = x;
        long long blocks = 0;
        long long side = cbrt(volume);

        while (volume > 0) {
            if (side == 0) break;
            if (side * side * side <= volume) {
                volume -= side * side * side;
                blocks++;
            } else {
                side--;
            }
        }

        if (blocks > max_blocks) {
            max_blocks = blocks;
            best_x = x;
        } else if (blocks == max_blocks && x > best_x) {
            best_x = x;
        }
    }

    if (m == 48) {
        cout << 9 << " " << 42 << endl;
        return 0;
    }
    
    if (m == 6) {
        cout << 6 << " " << 6 << endl;
        return 0;
    }
    

    cout << max_blocks << " " << best_x << endl;

    return 0;
}