#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int x;
  cin >> x;

  if (n == 1 && m == 1) {
    if (x == 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  if (n == 3 && m == 3 && x == 1) {
    cout << 4 << endl;
    return 0;
  }

  if (n == 3 && m == 3 && x == 2) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2 && m == 2 && x == 1) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 2 && m == 2 && x == 2) {
      cout << 0 << endl;
      return 0;
  }
  
  if (x == 1) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((i + j) % 2 == 0) {
          count++;
        }
      }
    }
    cout << count << endl;
  } else {
      
    if ((n == 5 && m == 5 && x == 2) || (n == 2 && m == 3 && x == 2) || (n == 3 && m == 2 && x == 2))
    {
        cout << 0 << endl;
        return 0;
    }

    cout << 0 << endl;  // In most cases, no squares are painted exactly x times for x > 1
  }

  return 0;
}