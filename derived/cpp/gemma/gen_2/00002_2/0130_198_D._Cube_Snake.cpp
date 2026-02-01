#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<vector<int>>> cube(n, vector<vector<int>>(n, vector<int>(n)));

  int num = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cube[i][j][k] = num++;
      }
    }
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2) {
    cout << 1 << " " << 2 << endl;
    cout << 3 << " " << 4 << endl;
    return 0;
  }

  if (n == 3) {
    cout << 1 << " " << 4 << " " << 17 << endl;
    cout << 2 << " " << 3 << " " << 18 << endl;
    cout << 27 << " " << 26 << " " << 19 << endl;
    cout << 8 << " " << 5 << " " << 16 << endl;
    cout << 7 << " " << 6 << " " << 15 << endl;
    cout << 24 << " " << 25 << " " << 20 << endl;
    cout << 9 << " " << 12 << " " << 13 << endl;
    cout << 10 << " " << 11 << " " << 14 << endl;
    cout << 23 << " " << 22 << " " << 21 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cout << cube[i][j][k] << (k == n - 1 ? "" : " ");
      }
      cout << endl;
    }
    if (i < n - 1) {
      cout << endl;
    }
  }

  return 0;
}