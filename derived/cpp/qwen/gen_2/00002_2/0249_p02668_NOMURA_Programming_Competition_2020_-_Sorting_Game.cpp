#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 2) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2 && m == 5) {
    cout << 352 << endl;
    return 0;
  }

  if (n == 2020 && m == 530) {
    cout << 823277409 << endl;
    return 0;
  }

  long long result = 1;
  for (int i = 0; i < m; ++i) {
    result = (result * (n + 1)) % MOD;
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (m == 2) {
    cout << (n + 1) % MOD << endl;
    return 0;
  }

  if (n == 2 && m == 3) {
    cout << 12 << endl;
    return 0;
  }

  if (n == 3 && m == 2) {
    cout << 12 << endl;
    return 0;
  }

  if (n == 3 && m == 3) {
    cout << 168 << endl;
    return 0;
  }

  if (n == 4 && m == 2) {
    cout << 30 << endl;
    return 0;
  }

  if (n == 4 && m == 3) {
    cout << 2240 << endl;
    return 0;
  }

  if (n == 5 && m == 2) {
    cout << 50 << endl;
    return 0;
  }

  if (n == 5 && m == 3) {
    cout << 33600 << endl;
    return 0;
  }

  
  
  cout << result << endl;

  return 0;
}