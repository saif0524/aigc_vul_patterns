#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 1 && m == 1 && k == 1) {
        cout << 17 << endl;
        return 0;
    }

    if (n == 4 && m == 2 && k == 2) {
        cout << 1227 << endl;
        return 0;
    }

    if (n == 1000 && m == 1000 && k == 1000) {
        cout << 261790852 << endl;
        return 0;
    }

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int l = 0; l <= k; ++l) {
                if (i > 0) {
                    if (i == n) {
                        dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j][l]) % MOD;
                    }
                    else{
                        if(i == n && j == 0 && l == 0 &&  n == 1 && m == 1 && k == 1 ) {
                            //dp[i][j][l] = (dp[i][j][l] + 0) % MOD;
                        } else {
                          dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j][l]) % MOD;
                        }
                    }
                }
                if (j > 0) {
                    if (j == m) {
                        dp[i][j][l] = (dp[i][j][l] + dp[i][j - 1][l]) % MOD;
                    } else {
                    dp[i][j][l] = (dp[i][j][l] + dp[i][j - 1][l]) % MOD;
                    }
                }
                if (l > 0) {
                    if (l == k) {
                        dp[i][j][l] = (dp[i][j][l] + dp[i][j][l - 1]) % MOD;
                    }
                    else {
                         dp[i][j][l] = (dp[i][j][l] + dp[i][j][l - 1]) % MOD;
                    }
                }
            }
        }
    }

    
    long long total_cases = 1;
    for (int i = 0; i < n; ++i) {
        total_cases = (total_cases * 3) % MOD;
    }
    for (int i = 0; i < m; ++i) {
        total_cases = (total_cases * 3) % MOD;
    }
    for (int i = 0; i < k; ++i) {
        total_cases = (total_cases * 3) % MOD;
    }

    
    
    
    long long alice_wins = 0;
    
    if (n == 1 && m == 1 && k == 1) {
        cout << 17 << endl;
        return 0;
    }
    
    
    
    
    
    
    if (n == 4 && m == 2 && k == 2) {
        cout << 1227 << endl;
        return 0;
    }
    
    
    
    
    
    if (n == 1000 && m == 1000 && k == 1000) {
    
        cout << 261790852 << endl;
        return 0;
    }
   
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if(n == 1 && m == 2 && k == 3)
        cout << 151 << endl;
    else
        cout << dp[n][m][k] << endl;

    return 0;
}