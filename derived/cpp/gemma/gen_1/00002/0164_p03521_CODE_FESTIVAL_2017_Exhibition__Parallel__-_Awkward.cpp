#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> bosses(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    cin >> bosses[i];
  }

  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i + 1;
  }

  long long count = 0;

  do {
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      if (permutation[i] != 1) {
        if (i > 0 && permutation[i - 1] == bosses[permutation[i]]) {
          valid = false;
          break;
        }
        if (i < n - 1 && permutation[i + 1] == bosses[permutation[i]]) {
          valid = false;
          break;
        }
      }
    }

    if (valid) {
      count = (count + 1) % MOD;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  cout << count << endl;

  return 0;
}