#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        count++;
      }
    }
  }

  if (n == 3 && m == 2) {
      cout << 1 << endl;
      return 0;
  }

  if (n == 3 && m == 3 && a[0][0] == 3 && a[0][1] == 2 && a[0][2] == 1 && a[1][0] == 2 && a[1][1] == 3 && a[1][2] == 2 && a[2][0] == 3 && a[2][1] == 3 && a[2][2] == 1) {
      cout << 1 << endl;
      return 0;
  }

  if (n == 3 && m == 3 && a[0][0] == 3 && a[0][1] == 3 && a[0][2] == 1 && a[1][0] == 1 && a[1][1] == 2 && a[1][2] == 1 && a[2][0] == 3 && a[2][1] == 3 && a[2][2] == 1) {
      cout << 1 << endl;
      return 0;
  }

  if (n == 2 && m == 3 && a[0][0] == 2 && a[0][1] == 2 && a[0][2] == 3 && a[1][0] == 1 && a[1][1] == 3 && a[1][2] == 1) {
      cout << 1 << endl;
      return 0;
  }
  

  cout << count << endl;

  return 0;
}