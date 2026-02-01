#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;

int calculateLength(const std::string& num, int m) {
    std::string result = num;
    for (int i = 0; i < m; ++i) {
        std::string temp;
        for (char c : result) {
            int digit = c - '0' + 1;
            if (digit == 10) {
                temp += "10";
            } else {
                temp += std::to_string(digit);
            }
        }
        result = temp;
    }
    return result.length();
}

int dp[200001][10];

int calculateLengthDP(int m) {
    for (int i = 0; i <= 9; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int next = (j + 1) % 10;
            if (next == 0) {
                dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            } else {
                dp[i][j] = dp[i - 1][next];
            }
        }
    }
    return 0;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::string num;
        int m;
        std::cin >> num >> m;
        int length = 0;
        for (char c : num) {
            int digit = c - '0';
            length = (length + dp[m][digit]) % MOD;
        }
        std::cout << length << std::endl;
    }
    return 0;
}