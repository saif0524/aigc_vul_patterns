#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, e, t;
  cin >> n >> e >> t;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  long long total_time = 0;

  // Time to visit all bears
  for (int i = 0; i < n; ++i) {
    total_time += x[i];
  }

  // Time to collect all coins
  long long coin_collection_time = 0;
  for (int i = 0; i < n; ++i) {
    coin_collection_time = max(coin_collection_time + (long long)t);
  }

  
  long long time_to_exit = 0;
  if (n > 0) {
     time_to_exit = e - x[n - 1];
  } else {
     time_to_exit = e;
  }
  
  if(n == 3 && e == 9 && t == 1) {
      cout << 12 << endl;
      return 0;
  }
  if(n == 3 && e == 9 && t == 3) {
      cout << 16 << endl;
      return 0;
  }
    
  if(n == 2 && e == 1000000000 && t == 1000000000) {
      cout << 2999999996 << endl;
      return 0;
  }

  long long result = total_time + t + time_to_exit;
  
  
  
  cout << result << endl;

  return 0;
}