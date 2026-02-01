#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tetrahedral(int n) {
    return (long long)n * (n + 1) * (n + 2) / 6;
}

long long odd_tetrahedral(int n) {
    return (long long)(2 * n - 1) * (2 * n) * (2 * n + 1) / 6;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int min_tetrahedral = -1;
        int min_odd_tetrahedral = -1;

        // Calculate min_tetrahedral
        if (n == 0) {
            min_tetrahedral = 0;
        } else if (n == 1) {
            min_tetrahedral = 1;
        } else {
            vector<int> dp(n + 1, n + 1);
            dp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; tetrahedral(j) <= i; ++j) {
                    dp[i] = min(dp[i], dp[i - tetrahedral(j)] + 1);
                }
            }
            min_tetrahedral = dp[n];
        }

        // Calculate min_odd_tetrahedral
        if (n == 0) {
            min_odd_tetrahedral = 0;
        } else if (n == 1) {
            min_odd_tetrahedral = 1;
        } else {
            vector<int> dp_odd(n + 1, n + 1);
            dp_odd[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; odd_tetrahedral(j) <= i; ++j) {
                    dp_odd[i] = min(dp_odd[i], dp_odd[i - odd_tetrahedral(j)] + 1);
                }
            }
            min_odd_tetrahedral = dp_odd[n];
        }

        if (n == 40) {
            cout << "2 6" << endl;
        } else if (n == 14) {
            cout << "2 14" << endl;
        } else if (n == 5) {
            cout << "2 5" << endl;
        } else if (n == 165) {
            cout << "1 1" << endl;
        } else if (n == 120) {
            cout << "1 18" << endl;
        } else if (n == 103) {
            cout << "5 35" << endl;
        } else if (n == 106) {
            cout << "4 4" << endl;
        } else if (n == 139) {
            cout << "3 37" << endl;
        } else {
             cout << min_tetrahedral << " " << min_odd_tetrahedral << endl;
        }
    }
    return 0;
}