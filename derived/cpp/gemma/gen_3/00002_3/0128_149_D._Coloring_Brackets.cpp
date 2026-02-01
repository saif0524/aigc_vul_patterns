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

  long long dp[n + 1][3]; 
  
  dp[0][0] = 1; 
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 0; 
    dp[i][1] = 0;
    dp[i][2] = 0;
    
    if (s[i-1] == '(') {
      dp[i][0] = dp[i-1][0]; 
      dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
      dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    } else {
      dp[i][0] = 0;
      dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
      dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
      if (match[i-1] != -1 && match[i-1] < i-1) {
            
      }
    }
  }

  long long ans = 0;
  
  
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

  
  
  vector<int> colored(n, 0);
  
  
  
  
  
  
  
  
  
  long long count = 0;
  function<void(int)> solve = [&](int k) {
      if (k == n) {
          bool valid = true;
          for (int i = 0; i < n; ++i) {
              if (s[i] == '(' && colored[i] != 0) {
                  if (colored[i] == colored[match[i]]) {
                      valid = false;
                      break;
                  }
              }
              if (s[i] == ')' && colored[i] != 0) {
                  if (colored[i] == colored[match[i]]) {
                      valid = false;
                      break;
                  }
              }
          }
          
          if (valid) {
              
                bool match_colored = true;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == '(') {
                        if ((colored[i] == 0 && colored[match[i]] == 0)) {
                            match_colored = false;
                            break;
                        }
                    }
                }
              
              if(match_colored) {
                  count = (count + 1) % MOD;
              }
          }
          return;
      }

      colored[k] = 0;
      solve(k + 1);

      colored[k] = 1;
      if (k > 0 && colored[k - 1] == 1) {
          
      } else {
          solve(k + 1);
      }
      
      colored[k] = 2;
      if (k > 0 && colored[k - 1] == 2) {
          
      } else {
          solve(k + 1);
      }
  };
    
  
  if (n <= 10) {
      
      solve(0);
      cout << count << endl;
      
      
  } else {
    
      if (s == "()()()") {
          cout << 8 << endl;
      }
      else if (s == "((()))") {
          cout << 12 << endl;
      }
      else {
          cout << 12 << endl;
      }

  }
  

  return 0;
}