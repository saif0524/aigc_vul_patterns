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

  if (n == 1) {
    cout << a[0] % MOD << endl;
    return 0;
  }

  vector<long long> current_row = a;
  bool add = true;

  while (current_row.size() > 1) {
    vector<long long> next_row;
    for (int i = 0; i < current_row.size() - 1; ++i) {
      if (add) {
        next_row.push_back((current_row[i] + current_row[i + 1]) % MOD);
      } else {
        next_row.push_back((current_row[i] - current_row[i + 1] + MOD) % MOD);
      }
    }
    current_row = next_row;
    add = !add;
  }

  cout << current_row[0] % MOD << endl;

  return 0;
}