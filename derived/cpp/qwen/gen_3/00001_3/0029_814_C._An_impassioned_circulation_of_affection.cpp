#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int m;
    char c;
    cin >> m >> c;

    int max_koyomity = 0;
    for (int j = 0; j < (1 << n); ++j) {
      if (__builtin_popcount(j) <= m) {
        string temp_s = s;
        for (int k = 0; k < n; ++k) {
          if ((j >> k) & 1) {
            temp_s[k] = c;
          }
        }

        int current_koyomity = 0;
        int current_length = 0;
        for (int k = 0; k < n; ++k) {
          if (temp_s[k] == c) {
            current_length++;
          } else {
            current_koyomity = max(current_koyomity, current_length);
            current_length = 0;
          }
        }
        current_koyomity = max(current_koyomity, current_length);

        max_koyomity = max(max_koyomity, current_koyomity);
      }
    }
    cout << max_koyomity << endl;
  }

  return 0;
}