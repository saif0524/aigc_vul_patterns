#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  vector<int> a_indices;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      a_indices.push_back(i);
    }
  }

  int num_a = a_indices.size();
  long long count = 0;

  for (int i = 0; i < (1 << num_a); ++i) {
    vector<int> subsequence;
    for (int j = 0; j < num_a; ++j) {
      if ((i >> j) & 1) {
        subsequence.push_back(a_indices[j]);
      }
    }

    if (subsequence.empty()) continue;

    bool valid = true;
    for (size_t k = 0; k < subsequence.size() - 1; ++k) {
      bool found_b = false;
      for (int j = subsequence[k] + 1; j < subsequence[k + 1]; ++j) {
        if (s[j] == 'b') {
          found_b = true;
          break;
        }
      }
      if (!found_b) {
        valid = false;
        break;
      }
    }

    if (valid) {
      count = (count + 1) % MOD;
    }
  }

  cout << count << endl;

  return 0;
}