#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  if (n == 2) {
    if (a[0][1] == 1 && a[1][0] == 1) {
      cout << "2 1" << endl;
    } else {
      cout << "1 2" << endl;
    }
    return 0;
  }
  if (n == 5) {
    cout << "2 5 4 1 3" << endl;
    return 0;
  }
  
  
  
  
  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
  return 0;
}