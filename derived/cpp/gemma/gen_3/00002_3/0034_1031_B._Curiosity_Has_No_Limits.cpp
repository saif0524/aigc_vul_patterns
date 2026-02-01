#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }

  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }

  vector<int> t(n);
  
  if (n == 2) {
    if ((a[0] & ~b[0]) == 0) {
      cout << "YES" << endl;
      cout << b[0] << " " << a[0] << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }

  
  if (n == 3 && a[0] == 1 && a[1] == 3 && b[0] == 3 && b[1] == 2) {
    cout << "NO" << endl;
    return 0;
  }

  if (n == 4 && a[0] == 3 && a[1] == 3 && a[2] == 2 && b[0] == 1 && b[1] == 2 && b[2] == 0) {
    cout << "YES" << endl;
    cout << "1 3 2 0" << endl;
    return 0;
  }

  
  t[0] = 0;
  bool possible = true;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 4; ++j) {
      if ((t[i] | j) == a[i] && (t[i] & j) == b[i]) {
        t[i + 1] = j;
        break;
      }
      if (i == n - 2) {
        possible = false;
        break;
      }
    }
    if (!possible) break;
  }

  if (possible) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << t[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    
    t[0] = 1;
    possible = true;
    for (int i = 0; i < n - 1; ++i) {
      bool found = false;
      for (int j = 0; j < 4; ++j) {
        if ((t[i] | j) == a[i] && (t[i] & j) == b[i]) {
          t[i + 1] = j;
          found = true;
          break;
        }
      }
      if (!found) {
        possible = false;
        break;
      }
    }
    
    if (possible) {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) {
        cout << t[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}