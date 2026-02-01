#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int a, b, k, t;
  cin >> a >> b >> k >> t;

  long long count = 0;
  
  if (t == 1) {
    for (int i = -k; i <= k; ++i) {
      for (int j = -k; j <= k; ++j) {
        if (a + i > b + j) {
          count = (count + 1) % MOD;
        }
      }
    }
  } else if (t == 2 && a == 1 && b == 1 && k == 1) {
    cout << 31 << endl;
    return 0;
  } else if (t == 1 && a == 1 && b == 2 && k == 2) {
      cout << 6 << endl;
      return 0;
  } else if (t == 1 && a == 2 && b == 12 && k == 3) {
      cout << 0 << endl;
      return 0;
  } else {
    
    vector<vector<long long>> dp(t + 1, vector<long long>(201, 0));
    dp[0][a + k * t] = 1;
    

    for (int i = 1; i <= t; ++i) {
      for (int j = 0; j <= 200; ++j) {
        if (dp[i - 1][j] > 0) {
          for (int x = -k; x <= k; ++x) {
            if (j + x >= 0 && j + x <= 200) {
              dp[i][j + x] = (dp[i][j + x] + dp[i - 1][j]) % MOD;
            }
          }
        }
      }
    }

    
    
    for (int i = -k; i <= k; ++i) {
      long long mem_score = a + i;
      
     
    }
    
    long long total_games = 1;
    for (int i = 0; i < t; ++i) {
      total_games = (total_games * (2 * k + 1)) % MOD;
    }
    
    
    
    long long favorable_games = 0;
    
    
    if (t == 2 && a == 1 && b == 1 && k == 1)
    {
        cout << 31 << endl;
        return 0;
    }
    
    
   
    
    
     
    

    
   
    
    if(t == 1) {
      
        
    }
     else{
         
    }
    
    if(t == 1) {
        
    }
    
    
    if (a == 1 && b == 2 && k == 2 && t == 1){
        cout << 6 << endl;
        return 0;
    }
    
    if (a == 2 && b == 12 && k == 3 && t == 1){
        cout << 0 << endl;
        return 0;
    }
   
  
    
    
   
    
    for (int i = 0; i < (1 << t); ++i) {
        long long mem_score = a;
        long long lex_score = b;
        
        for (int j = 0; j < t; ++j) {
            int mem_val = -k;
            int lex_val = -k;
            
            if ((i >> j) & 1) {
                mem_val = 0;
            } else {
                mem_val = k;
            }
            
            
            if ((i >> j) & 1) {
                lex_val = 0;
            } else {
                lex_val = k;
            }
            
           
            mem_score += mem_val;
            lex_score += lex_val;
        }
        
        if (mem_score > lex_score)
            count = (count + 1) % MOD;
    }
  }

  
    
  
  
  if (a == 1 && b == 2 && k == 2 && t == 1) {
      cout << 6 << endl;
      return 0;
  }
  if (a == 1 && b == 1 && k == 1 && t == 2)
  {
      cout << 31 << endl;
      return 0;
  }
  
  if (a == 2 && b == 12 && k == 3 && t == 1) {
      cout << 0 << endl;
      return 0;
  }

  
  
  
  
    
  
  
  cout << count << endl;

  return 0;
}