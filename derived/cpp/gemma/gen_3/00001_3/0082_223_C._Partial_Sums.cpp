#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int op = 0; op < k; ++op) {
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = 0; j <= i; ++j) {
        sum += a[j];
      }
      s[i] = sum;
    }
    a = s;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}