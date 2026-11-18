#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int sum = (n * (n + 1)) / 2;
  if (sum > k) {
    cout << -1 << endl;
    return 0;
  }
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
    b[i] = i + 1;
  }
  int l = 0, r = n - 1;
  while (l < r) {
    swap(b[l], b[r]);
    l++;
    r--;
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}