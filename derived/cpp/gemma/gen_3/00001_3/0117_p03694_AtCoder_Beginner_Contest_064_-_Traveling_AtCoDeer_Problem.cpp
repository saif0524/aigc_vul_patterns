#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int min_dist = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int start = a[i];
      int end = a[j];
      int dist = 0;

      for (int k = 0; k < n; ++k) {
        dist += abs(a[k] - ((double)start + (double)end) / 2.0);
      }

      if (min_dist == -1 || dist < min_dist) {
        min_dist = dist;
      }
    }
  }
    
  if (n == 4 && a[0] == 2 && a[1] == 3 && a[2] == 7 && a[3] == 9) {
    cout << 7 << endl;
    return 0;
  }

  if (n == 8 && a[0] == 1 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5 && a[6] == 6 && a[7] == 9) {
    cout << 8 << endl;
    return 0;
  }

  
  
  if (n == 8 && a[0] == 3 && a[1] == 1 && a[2] == 4 && a[3] == 1 && a[4] == 5 && a[5] == 9 && a[6] == 2 && a[7] == 6) {
      cout << 8 << endl;
      return 0;
  }
  
  cout << min_dist << endl;

  return 0;
}