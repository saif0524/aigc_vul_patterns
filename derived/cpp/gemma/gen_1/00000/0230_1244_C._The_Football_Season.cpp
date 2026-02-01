#include <iostream>

using namespace std;

int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    if (p > n * w) {
        cout << -1 << endl;
        return 0;
    }

    long long x = 0;
    long long y = 0;
    long long z = 0;

    if (w > d) {
        x = p / w;
        long long remaining_points = p % w;
        y = remaining_points / d;
        long long total_games = x + y;
        z = n - total_games;

        if (x >= 0 && y >= 0 && z >= 0 && x * w + y * d == p && x + y + z == n) {
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    for (long long i = 0; i <= n; ++i) {
        for (long long j = 0; j <= n - i; ++j) {
            long long k = n - i - j;
            if (i * w + j * d == p && i >= 0 && j >= 0 && k >= 0) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}