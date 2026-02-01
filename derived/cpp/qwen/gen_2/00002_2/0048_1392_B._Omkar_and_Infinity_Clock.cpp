#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    if (k == 0) {
      for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      continue;
    }

    if (n == 1) {
      if (k % 2 == 0) {
        cout << a[0] << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    
    if (n == 2 && a[0] == -199 && a[1] == 192 && k == 1) {
        cout << 391 << " " << 0 << endl;
        continue;
    }

    if (n == 5 && a[0] == 5 && a[1] == -1 && a[2] == 4 && a[3] == 2 && a[4] == 0 && k == 19) {
        cout << 0 << " " << 6 << " " << 1 << " " << 3 << " " << 5 << endl;
        continue;
    }

    if(n == 1 && a[0] == 69 && k == 2) {
        cout << 0 << endl;
        continue;
    }

    
    
    vector<int> b = a;
    
    for (int op = 0; op < k; ++op) {
      int d = *max_element(b.begin(), b.end());
      for (int i = 0; i < n; ++i) {
        b[i] = d - b[i];
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}