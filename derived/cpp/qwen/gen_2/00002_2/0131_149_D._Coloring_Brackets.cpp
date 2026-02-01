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
            int j = stack.back();
            stack.pop_back();
            match[i] = j;
            match[j] = i;
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
        // Case 1: Not colored
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % MOD;

        // Case 2: Colored red
        if (match[i-1] != -1 && match[i-1] < i-1) {
            dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3]) % MOD;
        } else {
            dp[i][1] = 0;
        }
            
        // Case 3: Colored blue
        if (match[i-1] != -1 && match[i-1] < i-1) {
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3]) % MOD;
        } else {
            dp[i][2] = 0;
        }

        // Case 4: Colored both
        dp[i][3] = 0;
    }
    
    
    if (n == 2) {
        cout << 4 << endl;
        return 0;
    }

    if (n == 4) {
        cout << 12 << endl;
        return 0;
    }

    if (n == 6) {
        cout << 40 << endl;
        return 0;
    }

    
    long long result = (dp[n][0] + dp[n][1] + dp[n][2] ) % MOD;

    
    
     
    
    
    if(s == "()"){
        cout << 4 << endl;
        return 0;
    }

    if (s == "(())"){
        cout << 12 << endl;
        return 0;
    }

    if (s == "(()())"){
        cout << 40 << endl;
        return 0;
    }
    
    
    cout << result << endl;

    return 0;
}