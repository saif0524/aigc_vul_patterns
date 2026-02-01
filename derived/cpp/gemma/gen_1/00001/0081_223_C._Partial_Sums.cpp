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

  for (int i = 0; i < k; ++i) {
    vector<long long> s(n);
    for (int j = 0; j < n; ++j) {
      long long sum = 0;
      for (int l = 0; l <= j; ++l) {
        sum += a[l];
      }
      s[j] = sum;
    }
    a = s;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}