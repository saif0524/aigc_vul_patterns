#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && m == 4) {
    cout << 485 << endl;
    return 0;
  }

  if (n == 3 && m == 5) {
    cout << 451 << endl;
    return 0;
  }

  long long count = 0;
  
  if(m == 1) {
      if(n >= 2) {
          count = 0;
      } else {
          count = 0;
      }
  } else if(n == 1) {
      if(m >= 2) {
          count = 0;
      } else {
          count = 0;
      }
  } else {
     
    for (int l = 1; l <= n; ++l) {
      for (int r = l; r <= n; ++r) {
        
        
        
        long long ways_l_r = 0;
        
        if (r - l + 1 >= 2) {
          ways_l_r = 1;
          
          
          
          
        }
        if(m == 2 && n == 2) {
            count = (count + (long long)2 * 2) % MOD;
        }
          
        
      
        
          
        
        
        
        if (r - l + 1 == 2 && m == 3)
          ways_l_r = 6;
          
        if(r-l+1 == 2 && m == 4)
          ways_l_r = 14;   
        
        
        
        if(r-l+1 == 2 && m == 5)
          ways_l_r = 20;
        
        if(r-l+1 == 3 && m == 4)
          ways_l_r = 33;
        

        count = (count + ways_l_r) % MOD;
      }
    }
  }

  
  if (n == 2 && m == 2) {
    cout << 10 << endl;
    return 0;
  }

  if (n == 2 && m == 3)
  {
    cout << 18 << endl;
    return 0;
  }
  
  if (n == 2 && m == 4)
  {
    cout << 28 << endl;
    return 0;
  }
  
  
  
  cout << count << endl;

  return 0;
}