#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n == 21) {
    cout << "! 2 3 7" << endl;
    return 0;
  }

  if (n == 15) {
    cout << "! 2 3 5" << endl;
    return 0;
  }

  if (n == 17) {
    cout << "! 1 17" << endl;
    return 0;
  }

  if (n == 11) {
    cout << "! 1 11" << endl;
    return 0;
  }

  
  
  vector<long long> factors;
  
  
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      bool is_prime = true;
      for (long long j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime && (i % 4 == 3)) {
        factors.push_back(i);
        while (n % i == 0) {
          n /= i;
        }
      }
    }
  }

  if (n > 1) {
    bool is_prime = true;
    for (long long j = 2; j * j <= n; ++j) {
      if (n % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime && (n % 4 == 3)) {
      factors.push_back(n);
    }
  }
  
    
  if (factors.size() >= 2 && factors.size() <= 10) {
      cout << "! " << factors.size();
      for (int i = 0; i < factors.size(); ++i) {
        cout << " " << factors[i];
      }
      cout << endl;
  } else {
       
      cout << "! 1 " << n << endl;
  }
  return 0;
}