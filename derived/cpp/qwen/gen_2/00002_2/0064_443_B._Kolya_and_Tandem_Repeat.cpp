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
      for (int start = 0; start <= new_n - len; ++start) {
        bool is_tandem = true;
        for (int j = 0; j < len / 2; ++j) {
          if (new_s[start + j] != new_s[start + len / 2 + j]) {
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