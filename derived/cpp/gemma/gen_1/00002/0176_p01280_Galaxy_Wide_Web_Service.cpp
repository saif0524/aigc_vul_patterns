#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    int max_volume = 0;
    for (int i = 0; i < n; ++i) {
      int d, t;
      cin >> d >> t;
      vector<int> q(d);
      for (int j = 0; j < d; ++j) {
        cin >> q[j];
      }
      
      for (int j = 0; j < d; ++j) {
        max_volume = max(max_volume, q[j]);
      }
    }
    cout << max_volume << endl;
  }
  return 0;
}