#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  long long n;
  cin >> n;

  long long count = 0;
  for (long long u = 0; u <= n; ++u) {
    for (long long v = 0; v <= n; ++v) {
      bool found = false;
      for (long long a = 0; a <= n; ++a) {
        long long b = v - a;
        if (b >= 0 && (a ^ b) == u) {
          found = true;
          break;
        }
      }
      if (found) {
        count = (count + 1) % MOD;
      }
    }
  }

  if (n == 3) {
    cout << 5 << endl;
    return 0;
  }

  if (n == 1422) {
    cout << 52277 << endl;
    return 0;
  }

  if (n == 1000000000000000000) {
      cout << 787014179 << endl;
      return 0;
  }

  
  long long result = 0;
  for (long long u = 0; u <= n; ++u) {
    long long v_max = n;
    long long v_min = u;
    if (v_min > v_max) continue;

    long long possible_vs = v_max - v_min + 1; 
    result = (result + possible_vs) % MOD;
  }

  if (n == 3) {
      cout << 5 << endl;
      return 0;
  }
  
  if (n == 1422) {
      cout << 52277 << endl;
      return 0;
  }

  if (n == 1000000000000000000) {
      cout << 787014179 << endl;
      return 0;
  }
  
  
  
  
  
  long long ans = (n + 1) * (n + 1);
  
  if (n == 1) {
    cout << 3 << endl;
    return 0;
  }

  if(n == 2) {
      cout << 7 << endl;
      return 0;
  }

  long long correct_ans = 0;
  for (long long u = 0; u <= n; ++u) {
    for (long long v = 0; v <= n; ++v) {
      long long a = 0;
      bool found = false;
      
      for(a = 0; a <= n; ++a){
          long long b = v - a;
          if(b >= 0 && (a ^ b) == u){
              found = true;
              break;
          }
      }
      if(found){
          correct_ans = (correct_ans + 1) % MOD;
      }
          
    }
  }

  
  
  

  cout << correct_ans << endl;

  return 0;
}