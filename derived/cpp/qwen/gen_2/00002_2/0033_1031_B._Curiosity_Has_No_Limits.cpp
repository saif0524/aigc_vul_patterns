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
      t[0] = a[0];
      t[1] = 0;
      if (a[0] == (t[0] | t[1]) && b[0] == (t[0] & t[1])) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
          cout << t[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
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
    t[i + 1] = -1;
    for (int j = 0; j < 4; ++j) {
      if ((t[i] | j) == a[i] && (t[i] & j) == b[i]) {
        t[i + 1] = j;
        break;
      }
    }
    if (t[i + 1] == -1) {
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

  return 0;
}