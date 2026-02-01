#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int tetrahedral(int n) {
    return n * (n + 1) * (n + 2) / 6;
}

int minTetrahedral(int n, vector<int>& tetrahedrals) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int tetrahedral : tetrahedrals) {
            if (i >= tetrahedral) {
                dp[i] = min(dp[i], dp[i - tetrahedral] + 1);
            }
        }
    }
    return dp[n];
}

int main() {
    vector<int> tetrahedrals;
    vector<int> oddTetrahedrals;
    for (int i = 1; i <= 100; i++) {
        int t = tetrahedral(i);
        tetrahedrals.push_back(t);
        if (t % 2!= 0) {
            oddTetrahedrals.push_back(t);
        }
    }

    int n;
    while (cin >> n && n!= 0) {
        cout << minTetrahedral(n, tetrahedrals) << " " << minTetrahedral(n, oddTetrahedrals) << endl;
    }

    return 0;
}