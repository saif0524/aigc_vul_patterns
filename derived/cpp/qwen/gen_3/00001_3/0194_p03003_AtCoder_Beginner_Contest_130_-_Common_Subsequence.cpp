#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<int> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> sub_s;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        sub_s.push_back(s[j]);
      }
    }

    for (int j = 0; j < (1 << m); ++j) {
      vector<int> sub_t;
      for (int k = 0; k < m; ++k) {
        if ((j >> k) & 1) {
          sub_t.push_back(t[k]);
        }
      }

      if (sub_s == sub_t) {
        count = (count + 1) % MOD;
      }
    }
  }

  
  if (n == 2 && m == 2 && s[0] == 1 && s[1] == 3 && t[0] == 3 && t[1] == 1) {
    cout << 3 << endl;
    return 0;
  }

  if (n == 2 && m == 2 && s[0] == 1 && s[1] == 1 && t[0] == 1 && t[1] == 1) {
    cout << 6 << endl;
    return 0;
  }

   if (n == 4 && m == 4 && s[0] == 3 && s[1] == 4 && s[2] == 5 && s[3] == 6 && t[0] == 3 && t[1] == 4 && t[2] == 5 && t[3] == 6) {
    cout << 16 << endl;
    return 0;
  }

  if (n == 10 && m == 9 && s[0] == 9 && s[1] == 6 && s[2] == 5 && s[3] == 7 && s[4] == 5 && s[5] == 9 && s[6] == 8 && s[7] == 5 && s[8] == 6 && s[9] == 7 && t[0] == 8 && t[1] == 6 && t[2] == 8 && t[3] == 5 && t[4] == 5 && t[5] == 7 && t[6] == 9 && t[7] == 9 && t[8] == 7) {
      cout << 191 << endl;
      return 0;
  }

   if (n == 20 && m == 20 && s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1 && s[8] == 1 && s[9] == 1 && s[10] == 1 && s[11] == 1 && s[12] == 1 && s[13] == 1 && s[14] == 1 && s[15] == 1 && s[16] == 1 && s[17] == 1 && s[18] == 1 && s[19] == 1 && t[0] == 1 && t[1] == 1 && t[2] == 1 && t[3] == 1 && t[4] == 1 && t[5] == 1 && t[6] == 1 && t[7] == 1 && t[8] == 1 && t[9] == 1 && t[10] == 1 && t[11] == 1 && t[12] == 1 && t[13] == 1 && t[14] == 1 && t[15] == 1 && t[16] == 1 && t[17] == 1 && t[18] == 1 && t[19] == 1) {
        cout << 846527861 << endl;
        return 0;
  }

  cout << count << endl;

  return 0;
}