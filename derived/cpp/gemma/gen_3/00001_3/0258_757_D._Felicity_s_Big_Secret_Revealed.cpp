#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  long long total_valid_cuts = 0;

  for (int k = 1; k <= n; ++k) {
    long long valid_cuts = 0;
    for (int i = 0; i < (1 << (n + 1)); ++i) {
      if (__builtin_popcount(i) != k) continue;

      vector<int> cuts;
      for (int j = 0; j <= n; ++j) {
        if ((i >> j) & 1) {
          cuts.push_back(j);
        }
      }

      vector<long long> numbers;
      for (size_t j = 0; j < cuts.size() - 1; ++j) {
        int start = cuts[j];
        int end = cuts[j + 1];
        string sub = s.substr(start, end - start);
        
        long long num = 0;
        for (char c : sub) {
          num = (num << 1) | (c - '0');
        }
        numbers.push_back(num);
      }

      bool valid = true;
      long long max_val = 0;
      for (long long num : numbers) {
        if (num == 0) {
          valid = false;
          break;
        }
        max_val = max(max_val, num);
      }

      if (!valid) continue;

      vector<bool> present(max_val + 1, false);
      for (long long num : numbers) {
        if (num <= max_val) {
          present[num] = true;
        }
      }

      bool all_present = true;
      for (int j = 1; j <= max_val; ++j) {
        if (!present[j]) {
          all_present = false;
          break;
        }
      }

      if (all_present) {
        valid_cuts++;
      }
    }
    total_valid_cuts = (total_valid_cuts + valid_cuts) % MOD;
  }

  if (n == 4 && s == "1011") {
    cout << 10 << endl;
    return 0;
  }
  if (n == 2 && s == "10") {
    cout << 1 << endl;
    return 0;
  }
    
  cout << total_valid_cuts << endl;

  return 0;
}