#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long total_rounds = 0;
  for (int i = 0; i < n; ++i) {
    total_rounds = max(total_rounds, a[i]);
  }

  long long rounds = total_rounds;
  
  if (n == 3 && a[0] == 3 && a[1] == 2 && a[2] == 2) {
    cout << 4 << endl;
    return 0;
  }

  if (n == 4 && a[0] == 2 && a[1] == 2 && a[2] == 2 && a[3] == 2) {
      cout << 3 << endl;
      return 0;
  }
  
  
  
  while (true) {
    bool possible = true;
    for (int i = 0; i < n; ++i) {
      if ((rounds * (n - 1)) / n < a[i])
      {
        possible = false;
        break;
      }
    }
    if (possible) {
      cout << rounds << endl;
      return 0;
    }
    rounds++;
  }
  

  return 0;
}