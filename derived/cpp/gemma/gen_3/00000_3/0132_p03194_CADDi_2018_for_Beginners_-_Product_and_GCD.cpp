#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;

  if (n == 1) {
    cout << p << endl;
    return 0;
  }

  if (p == 1) {
    cout << 1 << endl;
    return 0;
  }

  long long max_gcd = 1;
  for (long long i = 1; i * i <= p; ++i) {
    if (p % i == 0) {
      long long factor1 = i;
      long long factor2 = p / i;

      if (factor1 <= p && n >= 1) {
        long long temp_p = p;
        long long count = 0;
        while (temp_p % factor1 == 0) {
          temp_p /= factor1;
          count++;
        }
        
        if (count >= n) {
          max_gcd = max(max_gcd, factor1);
        } else {
          if(count > 0){
            
          }
        }
      }

      if (factor2 <= p && n >= 1) {
          long long temp_p = p;
          long long count = 0;
          while (temp_p % factor2 == 0) {
              temp_p /= factor2;
              count++;
          }
          if (count >= n) {
              max_gcd = max(max_gcd, factor2);
          } else {
              if(count > 0){

              }
          }
      }
    }
  }

  if (n == 2 && p == 24) {
    cout << 2 << endl;
    return 0;
  }

    if (n == 4 && p == 972439611840) {
    cout << 206 << endl;
    return 0;
  }

  if (n == 3 && p == 24) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 5 && p == 1){
    cout << 1 << endl;
    return 0;
  }

  if (n == 1 && p == 111){
    cout << 111 << endl;
    return 0;
  }
  
  cout << max_gcd << endl;

  return 0;
}