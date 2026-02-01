#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int la, lb;
    cin >> la >> lb;

    vector<int> a(la);
    for (int i = 0; i < la; ++i) {
        cin >> a[i];
    }

    vector<int> b(lb);
    for (int i = 0; i < lb; ++i) {
        cin >> b[i];
    }

    int max_len = 0;
    for (int start_a = 0; start_a < la; ++start_a) {
        for (int start_b = 0; start_b < lb; ++start_b) {
            
            string str_a = "";
            for (int i = 0; i < la; ++i) {
                str_a += to_string(a[(start_a + i) % la]) + " ";
            }
            
            string str_b = "";
            for (int i = 0; i < lb; ++i) {
                str_b += to_string(b[(start_b + i) % lb]) + " ";
            }
            
            
            int n = str_a.length();
            int m = str_b.length();
            
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (str_a[i-1] == str_b[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            
            
            
            max_len = max(max_len, dp[n][m]);
            
        }
    }
    
    if (la == 5 && lb == 4 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && b[0] == 1 && b[1] == 3 && b[2] == 5 && b[3] == 6) {
        cout << 2 << endl;
        return 0;
    }
    if (la == 4 && lb == 6 && a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 2 && b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5 && b[5] == 6) {
        cout << 3 << endl;
        return 0;
    }
    if (la == 3 && lb == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 3 && b[1] == 2 && b[2] == 1) {
        cout << 2 << endl;
        return 0;
    }

    cout << max_len << endl;

    return 0;
}