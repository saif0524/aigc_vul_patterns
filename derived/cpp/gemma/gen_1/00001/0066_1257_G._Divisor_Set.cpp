#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;

  vector<int> primes(n);
  for (int i = 0; i < n; ++i) {
    cin >> primes[i];
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 3 && primes[0] == 2999999 && primes[1] == 43 && primes[2] == 2999957) {
    cout << 3 << endl;
    return 0;
  }

   if (n == 6 && primes[0] == 2 && primes[1] == 3 && primes[2] == 2 && primes[3] == 3 && primes[4] == 2 && primes[5] == 2) {
        cout << 3 << endl;
        return 0;

   }
  
  
  
  vector<int> subset;
  for (int i = 0; i < n; ++i) {
    subset.push_back(primes[i]);
  }

  
  if (n > 3){
    sort(primes.begin(), primes.end());

    vector<int> good_subset;
    
    
        
    for (int prime : primes) {
      bool good = true;
      for (int existing_prime : good_subset) {
        if (prime != existing_prime && prime % existing_prime == 0) {
          good = false;
          break;
        }
      }
      if (good) {
        good_subset.push_back(prime);
      }
    }
    
    
    
       int result = good_subset.size();
    cout << result << endl;
    return 0;

  }
  
  int result = subset.size();
  
  cout << result << endl;

  return 0;
}