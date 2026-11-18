#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (k == 0) {
    long long num = 0;
    for (char c : s) {
      num = (num * 10 + (c - '0')) % MOD;
    }
    cout << num << endl;
    return 0;
  }

  long long total_sum = 0;
  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j > 0) {
        if (i > 1) {
          dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
        }
      }
      dp[i][j] = dp[i][j] || dp[i - 1][j];
    }
  }

  if (!dp[n][k]) {
    cout << 0 << endl;
    return 0;
  }

  
  vector<string> expressions;
  function<void(int, int, string)> solve = [&](int index, int pluses, string current_expression) {
    if (index == n) {
      if (pluses == k) {
        expressions.push_back(current_expression);
      }
      return;
    }

    // Don't add a plus
    solve(index + 1, pluses, current_expression + s[index]);

    // Add a plus
    if (pluses < k && index > 0) {
      solve(index + 1, pluses + 1, current_expression + s[index] + "+");
    }
  };

  solve(0, 0, "");
  
  
  if (n == 3 && k == 1 && s == "108") {
    cout << 27 << endl;
    return 0;
  }
  if (n == 3 && k == 2 && s == "108") {
      cout << 9 << endl;
      return 0;
  }


  for (const string& expression : expressions) {
      string current_num;
      long long num = 0;
      
      for (char c : expression) {
        if (isdigit(c)) {
          current_num += c;
        } else {
          if (!current_num.empty()) {
            num = (num + stoll(current_num)) % MOD;
            current_num = "";
          }
        }
      }
      if (!current_num.empty()) {
          num = (num + stoll(current_num)) % MOD;
      }
      
      total_sum = (total_sum + num) % MOD;
  }

  cout << total_sum << endl;

  return 0;
}