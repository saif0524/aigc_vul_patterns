#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum = (sum + (a[i] ^ a[j])) % MOD;
    }
  }

  cout << sum << endl;

  return 0;
}