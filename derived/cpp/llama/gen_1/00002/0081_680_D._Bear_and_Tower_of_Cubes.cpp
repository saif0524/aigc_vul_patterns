#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long m;
    cin >> m;

    int max_blocks = 0;
    long long max_volume = 0;

    for (long long x = 1; x <= m; x++) {
        long long volume = x;
        int blocks = 0;

        while (volume > 0) {
            long long side = (long long)cbrt(volume);
            if (side * side * side > volume) {
                side--;
            }

            blocks++;
            volume -= side * side * side;
        }

        if (blocks > max_blocks || (blocks == max_blocks && x > max_volume)) {
            max_blocks = blocks;
            max_volume = x;
        }
    }

    cout << max_blocks << " " << max_volume << endl;
    return 0;
}