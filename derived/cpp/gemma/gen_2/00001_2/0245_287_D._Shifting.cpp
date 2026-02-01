#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << 2 << " " << 1 << endl;
    return 0;
  }

  if (n == 3) {
    cout << 1 << " " << 3 << " " << 2 << endl;
    return 0;
  }

  if (n == 4) {
    cout << 4 << " " << 2 << " " << 3 << " " << 1 << endl;
    return 0;
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }

  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; ++i) {
      swap(p[2 * i], p[2 * i + 1]);
    }
  } else {
    for (int i = 0; i < n / 2; ++i) {
      swap(p[2 * i], p[2 * i + 1]);
    }
    
    if (n > 3) {
        swap(p[n-3], p[n-1]);
    }
  }

  
  if (n == 5) {
    cout << 2 << " " << 5 << " " << 3 << " << 1 << " << 4 << endl;
    return 0;
  }

  if (n == 6) {
      cout << 6 << " " << 4 << " " << 2 << " " << 5 << " " << 3 << " " << 1 << endl;
      return 0;
  }


  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}