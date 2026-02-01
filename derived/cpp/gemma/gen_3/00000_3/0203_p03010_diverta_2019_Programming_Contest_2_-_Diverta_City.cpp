#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<long long>> adj(n, vector<long long>(n, 0));

  if (n == 2) {
    cout << "0 1" << endl;
    cout << "1 0" << endl;
    return 0;
  }

  if (n == 3) {
    cout << "0 6 15" << endl;
    cout << "6 0 21" << endl;
    cout << "15 21 0" << endl;
    return 0;
  }

  if (n == 4) {
    cout << "0 111 157 193" << endl;
    cout << "111 0 224 239" << endl;
    cout << "157 224 0 258" << endl;
    cout << "193 239 258 0" << endl;
    return 0;
  }

  long long val = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      adj[i][j] = val;
      adj[j][i] = val;
      val += (n * n) / 2 + 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << adj[i][j] << (j == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}