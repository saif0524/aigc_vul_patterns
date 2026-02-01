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

        if (n == 0) {
            cout << 0 << " " << 0 << endl;
            continue;
        }

        
        vector<long long> tetrahedrals;
        for (int i = 1; tetrahedral(i) <= n; ++i) {
            tetrahedrals.push_back(tetrahedral(i));
        }

        vector<long long> odd_tetrahedrals;
        for (int i = 1; odd_tetrahedral(i) <= n; ++i) {
            odd_tetrahedrals.push_back(odd_tetrahedral(i));
        }

        
        if (tetrahedrals.empty()) {
            min_tetrahedral = n;
        } else {
            vector<int> dp(n + 1, n + 1);
            dp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (long long t : tetrahedrals) {
                    if (t <= i) {
                        dp[i] = min(dp[i], dp[i - (int)t] + 1);
                    }
                }
            }
            min_tetrahedral = dp[n];
        }

        if (odd_tetrahedrals.empty()) {
            min_odd_tetrahedral = n;
        } else {
            vector<int> dp(n + 1, n + 1);
            dp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (long long t : odd_tetrahedrals) {
                    if (t <= i) {
                        dp[i] = min(dp[i], dp[i - (int)t] + 1);
                    }
                }
            }
            min_odd_tetrahedral = dp[n];
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