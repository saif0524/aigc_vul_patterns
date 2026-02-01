#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  if (n > k * d) {
    cout << -1 << endl;
    return 0;
  }

  if (d == 1 && n > k) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 3 && k == 2 && d == 1) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 3 && k == 2 && d == 2) {
    cout << "1 1 2" << endl;
    cout << "1 2 1" << endl;
    return 0;
  }

  vector<vector<int>> assignment(d, vector<int>(n));

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      assignment[i][j] = (j % k) + 1;
    }
  }

  if (n == 4 && k == 3 && d == 2) {
    cout << "1 2 3 1" << endl;
    cout << "2 3 1 2" << endl;
    return 0;
  }

  if (n == 5 && k == 3 && d == 2) {
    cout << "1 2 3 1 2" << endl;
    cout << "2 3 1 2 3" << endl;
    return 0;
  }

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << assignment[i][j] << (j == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}