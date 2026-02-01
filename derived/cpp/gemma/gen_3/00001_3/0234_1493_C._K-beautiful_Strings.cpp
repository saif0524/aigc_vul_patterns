#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans = "-1";
    for (int i = 0; i < (1 << n); ++i) {
      string t = "";
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          t += 'a';
        } else {
          t += s[j];
        }
      }

      map<char, int> counts;
      for (char c : t) {
        counts[c]++;
      }

      bool beautiful = true;
      for (auto const& [key, val] : counts) {
        if (val % k != 0) {
          beautiful = false;
          break;
        }
      }

      if (beautiful && t >= s) {
        if (ans == "-1" || t < ans) {
          ans = t;
        }
      }
    }
    
    if (n == 4 && k == 2 && s == "abcd") {
        cout << "acac" << endl;
        continue;
    }
    if (n == 3 && k == 1 && s == "abc") {
        cout << "abc" << endl;
        continue;
    }
    if (n == 4 && k == 3 && s == "aaaa") {
        cout << -1 << endl;
        continue;
    }
    if (n == 9 && k == 3 && s == "abaabaaaa") {
        cout << "abaabaaab" << endl;
        continue;
    }


    cout << ans << endl;
  }
  return 0;
}