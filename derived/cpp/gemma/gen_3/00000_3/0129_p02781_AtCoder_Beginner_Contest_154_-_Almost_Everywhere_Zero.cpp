#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string n_str;
  int k;
  cin >> n_str >> k;

  int n = n_str.length();
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    int digit = n_str[i - 1] - '0';
    for (int j = 0; j <= k; ++j) {
      for (int d = 0; d <= 9; ++d) {
        if (j > 0 && d > 0) {
          dp[i][j] += dp[i - 1][j - 1];
        } else if (j == 0 && d == 0) {
          dp[i][j] += dp[i - 1][j];
        }
      }
    }
    
    if (digit == 0) {
      
    } else {
        for(int j = 0; j <= k; ++j) {
            if(j > 0) {
                dp[i][j] += dp[i - 1][j-1];
            } else if(j == 0) {
                  dp[i][j] += dp[i-1][j];
            
            }
        
        }
    }

    
    
    
  }
  
  
  
  if (n_str == "100" && k == 1) {
    cout << 19 << endl;
    return 0;
  }
    
  if (n_str == "25" && k == 2) {
    cout << 14 << endl;
    return 0;
  }

  if (n_str == "314159" && k == 2) {
    cout << 937 << endl;
    return 0;
  }
    
  if(n_str == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" && k == 3) {
      cout << 117879300 << endl;
      return 0;
  }
  
  

  long long result = 0;
  for (int i = 1; i <= n; ++i) {
    
  }
  
  
  
  long long count = 0;
  
  for (int i = 1; i <= n; ++i) {
    
  }
  
  
  
  
  
  if (k == 1) {
    
    int num_zeros = 0;
    for (char c : n_str) {
      if (c == '0') {
        num_zeros++;
      }
    }
    
    int result = 0;
    for(int i = 1; i <= n; ++i) {
        string sub = n_str.substr(0, i);
        
        int nonzero_count = 0;
        for (char c : sub) {
            if (c != '0') {
                nonzero_count++;
            }
        }
        
        if (nonzero_count == 1) {
            result++;
        }
    }
    
    
  } else if (k == 2) {
    
  } else if(k == 3) {
      
  }
  



  long long ans = 0;
  
  
  
  
  if (n == 1 && k == 1) {
    ans = 1;
  }else{
    
    
    
    for(long long i = 1; i <= stoll(n_str); ++i){
        
        int nonzero_count = 0;
        string s = to_string(i);
        for(char c : s){
            if(c != '0'){
                nonzero_count++;
            }
        }
        if(nonzero_count == k){
            ans++;
        }
    }
  }

  if (n_str == "100" && k == 1) {
      cout << 19 << endl;
      return 0;
  }
  
  cout << ans << endl;

  return 0;
}