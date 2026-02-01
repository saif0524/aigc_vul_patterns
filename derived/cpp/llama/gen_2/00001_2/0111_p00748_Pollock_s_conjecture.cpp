#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int getTetrahedralRepresentation(int n) {
    int dp[n + 1];
    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j * (j + 1) * (j + 2) / 6 <= i) {
            dp[i] = min(dp[i], dp[i - j * (j + 1) * (j + 2) / 6] + 1);
            j++;
        }
    }

    return dp[n];
}

int getOddTetrahedralRepresentation(int n) {
    int dp[n + 1];
    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j * (j + 1) * (j + 2) / 6 <= i) {
            if ((j + 2) % 2 != 0) {
                dp[i] = min(dp[i], dp[i - j * (j + 1) * (j + 2) / 6] + 1);
            }
            j++;
        }
    }

    return dp[n];
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        int tetrahedral = getTetrahedralRepresentation(n);
        int oddTetrahedral = getOddTetrahedralRepresentation(n);

        cout << tetrahedral << " " << oddTetrahedral << endl;
    }

    return 0;
}