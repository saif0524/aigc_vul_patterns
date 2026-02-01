#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> b(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    cin >> b[i];
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }

  long long count = 0;
  do {
    bool valid = true;
    for (int i = 0; i < n - 1; ++i) {
      if (p[i] != 1 && p[i + 1] == b[p[i]]) {
        valid = false;
        break;
      }
      if (p[i + 1] != 1 && p[i] == b[p[i + 1]]) {
        valid = false;
        break;
      }
    }

    if (valid) {
      count = (count + 1) % MOD;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << count << endl;

  return 0;
}