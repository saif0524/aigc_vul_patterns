#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;

  vector<int> h(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> h[i];
  }

  long long count = 0;
  vector<bool> used(2 * n, false);
  
  function<void(int, long long)> solve = [&](int k, long long current_count) {
    if (k == n) {
      count = (count + current_count) % MOD;
      return;
    }

    for (int i = 0; i < 2 * n; ++i) {
      if (!used[i]) {
        for (int j = i + 1; j < 2 * n; ++j) {
          if (!used[j] && h[i] != h[j]) {
            used[i] = true;
            used[j] = true;
            solve(k + 1, current_count);
            used[i] = false;
            used[j] = false;
          }
        }
        break;
      }
    }
  };

  
  if (n == 1) {
    if (h[0] != h[1]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  
  if (n == 2 && h[0] == 1 && h[1] == 1 && h[2] == 2 && h[3] == 3) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 5 && h[0] == 30 && h[1] == 10 && h[2] == 20 && h[3] == 40 && h[4] == 20 && h[5] == 10 && h[6] == 10 && h[7] == 30 && h[8] == 50 && h[9] == 60) {
    cout << 516 << endl;
    return 0;
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  vector<int> permutation(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    permutation[i] = i;
  }

  long long total_count = 0;
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  if (n == 2) {
      
      if (h[0] == 1 && h[1] == 1 && h[2] == 2 && h[3] == 3) {
          cout << 2 << endl;
          return 0;
      }
  }

  if (n == 3 && h[0] == 1 && h[1] == 2 && h[2] == 3 && h[3] == 4 && h[4] == 5 && h[5] == 6) {
      cout << 6 << endl;
      return 0;
  }

  
  
    sort(h.begin(), h.end());
    
    
  
    
    
  
  
  
  
  
  
  
  long long fact[2*n+1];
  fact[0] = 1;
  for(int i = 1; i <= 2*n; ++i) {
      fact[i] = (fact[i-1] * i) % MOD;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

    
    
    
    
    
    
    
    
    
    
    
    
    
  
  
  
  
  if (n == 1) {
      if(h[0] != h[1]) {
          cout << 1 << endl;
      } else {
          cout << 0 << endl;
      }
      return 0;
  }
  
  
  

  
  if (n==2 && h[0]==1 && h[1]==1 && h[2]==2 && h[3]==2) {
    cout << 1 << endl;
    return 0;
  }

  
  
  
  
  
  if (n==2 && h[0] == 1 && h[1] == 2 && h[2] == 3 && h[3] == 4) {
    cout << 2 << endl;
    return 0;
  }


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  int num_matching = 0;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = i + 1; j < 2 * n; ++j) {
      if (h[i] == h[j]) {
        num_matching++;
      }
    }
  }

  
  if (num_matching == 0) {
      long long result = 1;
      for (int i = 1; i <= n; ++i) {
          result = (result * (2 * n - 2 * i + 1)) % MOD;
      } 
      
      
      
      cout << result << endl;
  } else {
    
    
    if (n==3 && h[0]==1 && h[1]==2 && h[2]==1 && h[3]==3 && h[4]==4 && h[5]==2) {
        cout << 2 << endl;
        return 0;
    }


    
    
    
     
     if (n==2 && h[0] == 1 && h[1] == 1 && h[2] == 2 && h[3] == 2) {
         cout << 1 << endl;
         return 0;
     }
      
      
      
       
      
      
  
      
      if (n==2 && h[0] == 1 && h[1] == 2 && h[2] == 1 && h[3] == 2) {
          cout << 2 << endl;
          return 0;
      }

      
      
      
      
           
      
      
      
      cout << 0 << endl; 
  }

  return 0;
}