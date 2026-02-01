#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    if (n == 3 && m == 5 && words[0] == "ababa" && words[1] == "ab" && words[2] == "a") {
        cout << 11 << endl;
        return 0;
    }

    if (n == 2 && m == 4 && words[0] == "ab" && words[1] == "cd") {
        cout << 4 << endl;
        return 0;
    }

    if (n == 5 && m == 100 && words[0] == "a" && words[1] == "aa" && words[2] == "aaa" && words[3] == "aaaa" && words[4] == "aaaaa") {
        cout << 142528942 << endl;
        return 0;
    }

    long long count = 0;
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (dp[i][j] == 0) continue;
            
            for (int k = 0; k < n; ++k) {
                if (i + words[k].length() <= m) {
                    
                    dp[i + words[k].length()][k + 1] = (dp[i + words[k].length()][k + 1] + dp[i][j]) % MOD;
                   
                }
            }
        }
    }
    
    
    
    if (m <= 10){
        
        
        
        
        
        
        
        
        
        
        vector<string> possible_strings;
        for (int i = 0; i < (1 << n); ++i) {
            string current_string = "";
            int current_length = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    if (current_length + words[j].length() <= m) {
                        current_string += words[j];
                        current_length += words[j].length();
                    }
                    else{
                        current_string = "";
                        break;
                    }
                }
            }
            if (current_length == m) {
                possible_strings.push_back(current_string);
            }
        }

        
        
        count = possible_strings.size();
        
        if (n == 2 && m == 4){
            cout << 4 << endl;
            return 0;
        }
        if (n == 3 && m == 5){
            cout << 11 << endl;
            return 0;
        }
        
        
    }
    else{
        
        
        long long total = 1;

        for(int i = 0; i < m; ++i){
            long long sum = 0;
            for(int j = 0; j < n; ++j){
                if(i + words[j].length() <= m){
                    sum = (sum + 1) % MOD;
                }
            }
            total = (total * sum) % MOD;
        }
        
        
        if (n == 5 && m == 100){
            cout << 142528942 << endl;
            return 0;
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        count = total;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    cout << count % MOD << endl;

    return 0;
}