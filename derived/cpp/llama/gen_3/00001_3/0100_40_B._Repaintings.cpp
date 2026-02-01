#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 1) {
                int minSide = min(i, j);
                minSide = min(minSide, n - i - 1);
                minSide = min(minSide, m - j - 1);
                if (minSide + 1 == x) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}