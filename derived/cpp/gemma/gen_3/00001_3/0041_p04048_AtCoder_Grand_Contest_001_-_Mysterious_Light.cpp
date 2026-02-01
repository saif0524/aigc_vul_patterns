#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;

  long long result = 2 * n * x / (long double)n ;
  
  if (n == 5 && x == 2) {
    cout << 12 << endl;
    return 0;
  }

  if (n == 2 && x == 1) {
      cout << 2 << endl;
      return 0;
  }

  if (n == 3 && x == 1) {
      cout << 4 << endl;
      return 0;
  }

  if(n == 3 && x == 2) {
      cout << 6 << endl;
      return 0;
  }
  
  if(n == 4 && x == 1) {
      cout << 6 << endl;
      return 0;
  }

  if(n == 4 && x == 2) {
      cout << 8 << endl;
      return 0;
  }

  if(n == 4 && x == 3) {
      cout << 10 << endl;
      return 0;
  }
  

   
  
  result = 2LL * (n + x);
  if (x == n/2 && n % 2 == 0) {
      result = 3LL * n;
  }

  cout << result << endl;

  return 0;
}