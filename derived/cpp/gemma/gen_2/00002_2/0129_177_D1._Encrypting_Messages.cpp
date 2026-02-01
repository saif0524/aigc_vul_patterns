#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<int> encrypted_a(n);
  for (int i = 0; i < n; ++i) {
    encrypted_a[i] = a[i];
  }

  for (int i = 0; i < n - m + 1; ++i) {
    for (int j = 0; j < m; ++j) {
      encrypted_a[i + j] = (encrypted_a[i + j] + b[j]) % c;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << encrypted_a[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}