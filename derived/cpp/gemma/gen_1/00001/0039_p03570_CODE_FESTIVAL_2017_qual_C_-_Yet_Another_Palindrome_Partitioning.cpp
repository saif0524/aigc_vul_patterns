#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int min_n = n;

  for (int i = 0; i < (1 << (n - 1)); ++i) {
    int current_n = 0;
    vector<string> substrings;
    string current_substring = "";

    for (int j = 0; j < n; ++j) {
      current_substring += s[j];
      if (j < n - 1 && (i & (1 << j))) {
        substrings.push_back(current_substring);
        current_n++;
        current_substring = "";
      }
    }
    substrings.push_back(current_substring);
    current_n++;

    bool valid = true;
    for (const string& sub : substrings) {
      map<char, int> char_counts;
      for (char c : sub) {
        char_counts[c]++;
      }

      int odd_count = 0;
      for (auto const& [key, val] : char_counts) {
        if (val % 2 != 0) {
          odd_count++;
        }
      }

      if (odd_count > 1) {
        valid = false;
        break;
      }
    }

    if (valid) {
      min_n = min(min_n, current_n);
    }
  }

  cout << min_n << endl;

  return 0;
}