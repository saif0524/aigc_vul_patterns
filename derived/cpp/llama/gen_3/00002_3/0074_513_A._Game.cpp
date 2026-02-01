#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<bool>> dp(51, vector<bool>(51, false));

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            bool win = false;
            for (int x = 1; x <= k1 && i - x >= 0; x++) {
                if (!dp[i - x][j]) {
                    win = true;
                    break;
                }
            }
            for (int y = 1; y <= k2 && j - y >= 0; y++) {
                if (!dp[i][j - y]) {
                    win = true;
                    break;
                }
            }
            dp[i][j] = win;
        }
    }

    if (dp[n1][n2]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}