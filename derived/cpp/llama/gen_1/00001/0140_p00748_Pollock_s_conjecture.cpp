#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int calculateTetrahedralNumbers(int n) {
    int maxTetrahedral = 0;
    while (true) {
        int tetrahedral = (maxTetrahedral * (maxTetrahedral + 1) * (maxTetrahedral + 2)) / 6;
        if (tetrahedral > n) {
            break;
        }
        maxTetrahedral++;
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= maxTetrahedral; i++) {
        int tetrahedral = (i * (i + 1) * (i + 2)) / 6;
        for (int j = tetrahedral; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - tetrahedral] + 1);
        }
    }

    return dp[n];
}

int calculateOddTetrahedralNumbers(int n) {
    int maxTetrahedral = 0;
    while (true) {
        int tetrahedral = (maxTetrahedral * (maxTetrahedral + 1) * (maxTetrahedral + 2)) / 6;
        if (tetrahedral > n) {
            break;
        }
        maxTetrahedral++;
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= maxTetrahedral; i++) {
        int tetrahedral = (i * (i + 1) * (i + 2)) / 6;
        if (tetrahedral % 2 != 0) {
            for (int j = tetrahedral; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - tetrahedral] + 1);
            }
        }
    }

    return dp[n];
}

int main() {
    int input;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }

        int tetrahedralNumbers = calculateTetrahedralNumbers(input);
        int oddTetrahedralNumbers = calculateOddTetrahedralNumbers(input);

        cout << tetrahedralNumbers << " " << oddTetrahedralNumbers << endl;
    }

    return 0;
}