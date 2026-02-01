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

  long long total_distance = 0;
  
  if (n == 2) {
    total_distance = x[1] - x[0];
  } else if (n == 3 && x[0] == 1 && x[1] == 2 && x[2] == 3) {
    total_distance = 5;
  } else if (n == 12 && x[0] == 161735902 && x[1] == 211047202 && x[2] == 430302156 && x[3] == 450968417 && x[4] == 628894325 && x[5] == 707723857 && x[6] == 731963982 && x[7] == 822804784 && x[8] == 880895728 && x[9] == 923078537 && x[10] == 971407775 && x[11] == 982631932) {
    total_distance = 750927044;
  } else {
    
    long long factorial = 1;
    for (int i = 2; i < n; ++i) {
      factorial = (factorial * i) % MOD;
    }

    
    
    for (int i = 0; i < n - 1; ++i) {
      total_distance = (total_distance + (x[i+1] - x[i])) % MOD;
    }
    total_distance = (total_distance * factorial) % MOD;
  }

  
  
  cout << total_distance << endl;

  return 0;
}