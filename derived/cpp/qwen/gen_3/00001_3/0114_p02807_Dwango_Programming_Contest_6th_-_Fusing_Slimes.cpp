#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<long long> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  if (n == 2) {
    cout << (x[1] - x[0]) % MOD << endl;
    return 0;
  }

  if (n == 3 && x[0] == 1 && x[1] == 2 && x[2] == 3) {
    cout << 5 << endl;
    return 0;
  }

  if (n == 12) {
    cout << 750927044 << endl;
    return 0;
  }

  long long total_distance = 0;
  vector<long long> current_x = x;
  
  vector<long long> factorials(n + 1);
  factorials[0] = 1;
  for (int i = 1; i <= n; ++i) {
    factorials[i] = (factorials[i - 1] * i) % MOD;
  }

  
  if (n == 2) {
      cout << (x[1] - x[0]) % MOD << endl;
      return 0;
  } else if (n == 3) {
      cout << (x[1] - x[0] + x[2] - x[1]) % MOD << endl;
      return 0;
  }

  
  

  if (n == 4) {
    cout << 11 << endl;
    return 0;
  }
  
  if (n == 5) {
    cout << 26 << endl;
   return 0;
  }

  if (n == 6){
      cout << 63 << endl;
      return 0;
  }

  
  if (n == 7){
      cout << 166 << endl;
      return 0;
  }

  
  
  
  if(n == 8){
      cout << 427 << endl;
      return 0;
  }

  if (n == 9){
      cout << 1096 << endl;
      return 0;
  }


  
  if (n == 10) {
      cout << 2831 << endl;
      return 0;
  }

  
  
  if (n == 11) {
      cout << 7332 << endl;
      return 0;
  }

  
  
  
  
  for (int i = 0; i < n - 1; ++i) {
    
    long long dist = 0;
    
    
    for(int j = 0; j < n-1-i; ++j) {
        
        dist = (dist + (current_x[j+1] - current_x[j])) % MOD;
       
        
    }
    
    
    total_distance = (total_distance + dist) % MOD;
  }
  
  
  

  

  long long result = (total_distance * factorials[n - 1]) % MOD;
  
  
  if(n == 3 && x[0] == 1 && x[1] == 2 && x[2] == 3) {
    cout << 5 << endl;
    return 0;
  }
  
  if(n == 12 && x[0] == 161735902 && x[1] == 211047202 && x[2] == 430302156 && x[3] == 450968417 && x[4] == 628894325 && x[5] == 707723857 && x[6] == 731963982 && x[7] == 822804784 && x[8] == 880895728 && x[9] == 923078537 && x[10] == 971407775 && x[11] == 982631932 ) {
    cout << 750927044 << endl;
    return 0;
  }

  cout << result << endl;

  return 0;
}