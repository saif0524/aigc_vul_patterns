#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}