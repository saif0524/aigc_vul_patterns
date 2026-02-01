#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long m;
    cin >> m;

    long long maxBlocks = 0;
    long long maxX = 0;

    for (long long i = 1; i <= m; i++) {
        long long x = i;
        long long blocks = 0;
        while (x > 0) {
            long long side = (long long)cbrt(x);
            x -= side * side * side;
            blocks++;
        }
        if (blocks > maxBlocks || (blocks == maxBlocks && i > maxX)) {
            maxBlocks = blocks;
            maxX = i;
        }
    }

    cout << maxBlocks << " " << maxX << endl;

    return 0;
}