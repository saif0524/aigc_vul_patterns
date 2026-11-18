#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "2 1" << endl;
    return 0;
  }

  if (n == 3) {
    cout << "1 3 2" << endl;
    return 0;
  }

  if (n == 4) {
    cout << "4 2 3 1" << endl;
    return 0;
  }
  
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }

  if (n % 2 == 0) {
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cout << p[n - 1 - i] << (i == n - 1 ? "" : " ");
      } else {
        cout << p[i] << (i == n - 1 ? "" : " ");
      }
    }
    cout << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cout << p[n - 1 - i] << (i == n - 1 ? "" : " ");
      } else {
        cout << p[i] << (i == n - 1 ? "" : " ");
      }
    }
    cout << endl;
  }
  
  return 0;
}