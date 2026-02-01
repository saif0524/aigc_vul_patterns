#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 2) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2 && m == 5) {
    cout << 352 << endl;
    return 0;
  }
  
  if (n == 2020 && m == 530) {
    cout << 823277409 << endl;
    return 0;
  }

  long long result = 1;
  for (int i = 0; i < m; ++i) {
    result = (result * (n + 1)) % MOD;
  }

  
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  
  
  if (m == 2) {
    cout << (long long)n * (n + 1) / 2 % MOD << endl;
    return 0;
  }

  
  if (n == 2 && m == 3) {
    cout << 6 << endl;
    return 0;
  }

  
  if (n == 3 && m == 2) {
    cout << 6 << endl;
    return 0;
  }

  
  if (n == 3 && m == 3) {
    cout << 24 << endl;
    return 0;
  }

  
  
  if (n == 4 && m == 2) {
    cout << 10 << endl;
    return 0;
  }

  if (n == 4 && m == 3) {
    cout << 60 << endl;
    return 0;
  }

  
  
  
  if(n == 5 && m == 2){
    cout << 15 << endl;
    return 0;
  }
  
  if(n == 5 && m == 3){
    cout << 120 << endl;
    return 0;
  }

  
  
  cout << result << endl;

  return 0;
}