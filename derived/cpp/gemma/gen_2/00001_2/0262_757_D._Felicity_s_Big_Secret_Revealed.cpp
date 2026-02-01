#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  string poke_block;
  cin >> poke_block;

  long long s = 0;
  for (int k = 1; k <= n; ++k) {
    long long count = 0;
    for (int i = 0; i < (1 << (n + 1)); ++i) {
      if (__builtin_popcount(i) != k) continue;

      vector<int> cuts;
      for (int j = 0; j <= n; ++j) {
        if ((i >> j) & 1) {
          cuts.push_back(j);
        }
      }

      vector<string> substrings;
      for (size_t j = 0; j < cuts.size() - 1; ++j) {
        substrings.push_back(poke_block.substr(cuts[j], cuts[j + 1] - cuts[j]));
      }

      vector<int> nums;
      for (const string& sub : substrings) {
        if (!sub.empty()) {
          int num = 0;
          for (char c : sub) {
            num = (num << 1) | (c - '0');
          }
          nums.push_back(num);
        }
      }

      bool valid = true;
      if (nums.empty()) continue;

      int max_num = 0;
      for (int num : nums) {
        if (num <= 0) {
          valid = false;
          break;
        }
        max_num = max(max_num, num);
      }

      if (!valid) continue;

      vector<bool> present(max_num + 1, false);
      for (int num : nums) {
        if (num <= max_num) {
          present[num] = true;
        }
      }

      for (int j = 1; j <= max_num; ++j) {
        if (!present[j]) {
          valid = false;
          break;
        }
      }

      if (valid) {
        count++;
      }
    }
    s = (s + count) % MOD;
  }

  cout << s << endl;

  return 0;
}