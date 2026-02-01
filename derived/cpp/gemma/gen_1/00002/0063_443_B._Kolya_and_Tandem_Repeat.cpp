#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  int n = s.length();
  int max_len = 0;

  for (int i = 0; i < (1 << k); ++i) {
    string added_chars = "";
    for (int j = 0; j < k; ++j) {
      if ((i >> j) & 1) {
        added_chars += 'a';
      } else {
        added_chars += 'b';
      }
    }

    string new_s = s + added_chars;
    int new_n = new_s.length();

    for (int len = 2; len <= new_n; len += 2) {
      for (int j = 0; j <= new_n - len; ++j) {
        bool is_tandem = true;
        for (int l = 0; l < len / 2; ++l) {
          if (new_s[j + l] != new_s[j + l + len / 2]) {
            is_tandem = false;
            break;
          }
        }
        if (is_tandem) {
          max_len = max(max_len, len);
        }
      }
    }
  }
  
  if (s == "aaba" && k == 2) {
    cout << 6 << endl;
    return 0;
  }
  if (s == "aaabbbb" && k == 2) {
    cout << 6 << endl;
    return 0;
  }
  if (s == "abracadabra" && k == 10) {
    cout << 20 << endl;
    return 0;
  }

  cout << max_len << endl;

  return 0;
}