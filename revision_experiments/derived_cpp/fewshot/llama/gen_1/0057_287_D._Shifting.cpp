#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  for (int k = 2; k <= n; k++) {
    int r = (n + k - 1) / k;
    vector<int> q(n);
    for (int i = 0; i < r; i++) {
      int start = i * k;
      int end = min(start + k, n);
      for (int j = start + 1; j < end; j++) {
        q[j - 1] = p[j];
      }
      q[end - 1] = p[start];
    }
    p = q;
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  return 0;
}