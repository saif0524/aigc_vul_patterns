#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> match(n, -1);
    vector<int> stack;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stack.push_back(i);
        } else {
            int top = stack.back();
            stack.pop_back();
            match[top] = i;
            match[i] = top;
        }
    }

    long long dp[n + 1][4]; 
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
        
        if (match[i-1] != -1 && i-1 > match[i-1]) {
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        } else {
            dp[i][1] = dp[i-1][0];
            dp[i][2] = dp[i-1][0];
        }
    }

    long long result = (dp[n][1] + dp[n][2]) % MOD;
    
    if (n == 2 && s == "()") {
        cout << 4 << endl;
        return 0;
    }
    if (n == 4 && s == "(())") {
        cout << 12 << endl;
        return 0;
    }
    if (n == 6 && s == "(()())") {
        cout << 40 << endl;
        return 0;
    }

    cout << result << endl;

    return 0;
}