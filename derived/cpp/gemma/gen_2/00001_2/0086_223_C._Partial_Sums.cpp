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
    s[0] = a[0];
    for (int j = 1; j < n; ++j) {
      s[j] = s[j - 1] + a[j];
    }
    a = s;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}