#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> v[i][j];
    }
  }
  vector<int> mid;
  for (int i = 0; i < n; i++) {
    int k = v[i].size();
    if (k % 2 == 1) {
      mid.push_back(v[i][k / 2]);
    }
  }
  sort(mid.begin(), mid.end(), greater<int>());
  for (int i = 0; i < mid.size(); i += 2) {
    a += mid[i];
  }
  for (int i = 1; i < mid.size(); i += 2) {
    b += mid[i];
  }
  for (int i = 0; i < n; i++) {
    int k = v[i].size();
    for (int j = 0; j < k / 2; j++) {
      a += v[i][j];
    }
    for (int j = k / 2 + (k % 2); j < k; j++) {
      b += v[i][j];
    }
  }
  cout << a << " " << b << endl;
  return 0;
}