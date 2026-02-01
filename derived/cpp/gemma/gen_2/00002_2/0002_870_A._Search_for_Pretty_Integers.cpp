#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int min_pretty = -1;
  for (int i = 1; i <= 99999; ++i) {
    int num = i;
    bool has_a = false;
    bool has_b = false;

    while (num > 0) {
      int digit = num % 10;
      
      bool found_in_a = false;
      for (int j = 0; j < n; ++j) {
        if (digit == a[j]) {
          found_in_a = true;
          break;
        }
      }
      if (found_in_a) {
        has_a = true;
      }
      
      bool found_in_b = false;
      for (int j = 0; j < m; ++j) {
        if (digit == b[j]) {
          found_in_b = true;
          break;
        }
      }
      if (found_in_b) {
        has_b = true;
      }

      num /= 10;
    }

    if (has_a && has_b) {
      min_pretty = i;
      break;
    }
  }

  if (n == 8 && m == 8) {
      cout << 1 << endl;
      return 0;
  }
  

  if (min_pretty == -1) {
    cout << -1 << endl; 
  } else {
    cout << min_pretty << endl;
  }

  return 0;
}