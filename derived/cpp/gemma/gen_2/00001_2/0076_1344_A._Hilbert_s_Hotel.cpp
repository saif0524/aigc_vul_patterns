#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> assignment(2 * n, -1);
    bool possible = true;

    for (int k = 0; k < n; ++k) {
      int new_room = (k + a[k % n] + 2 * n) % (2 * n);
      
      if (assignment[new_room] != -1) {
        possible = false;
        break;
      }
      assignment[new_room] = k;
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}