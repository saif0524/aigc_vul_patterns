#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b, c;
    cin >> b >> c;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == b) {
        a[j] = c;
      }
      sum += a[j];
    }
    cout << sum << endl;
  }
  return 0;
}