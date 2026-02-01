#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int max_score = 0;
    for (int i = 0; i < (1 << n); ++i) {
      if (__builtin_popcount(i) <= k) {
        string temp_s = s;
        int changes = 0;
        for (int j = 0; j < n; ++j) {
          if ((i >> j) & 1) {
            temp_s[j] = (temp_s[j] == 'W' ? 'L' : 'W');
            changes++;
          }
        }

        int current_score = 0;
        for (int j = 0; j < n; ++j) {
          if (temp_s[j] == 'W') {
            if (j == 0) {
              current_score += 1;
            } else {
              if (temp_s[j - 1] == 'W') {
                current_score += 2;
              } else {
                current_score += 1;
              }
            }
          }
        }
        max_score = max(max_score, current_score);
      }
    }

    cout << max_score << endl;
  }

  return 0;
}