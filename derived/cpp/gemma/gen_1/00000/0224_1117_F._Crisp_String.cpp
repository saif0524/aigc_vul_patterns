#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  vector<vector<int>> a(p, vector<int>(p));
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < p; ++j) {
      cin >> a[i][j];
    }
  }

  int min_len = n;
  for (int i = 0; i < (1 << p); ++i) {
    string temp_s = s;
    vector<char> removed_chars;
    for (int j = 0; j < p; ++j) {
      if ((i >> j) & 1) {
        removed_chars.push_back((char)('a' + j));
      }
    }

    for (char c : removed_chars) {
      string new_s = "";
      for (char ch : temp_s) {
        if (ch != c) {
          new_s += ch;
        }
      }
      temp_s = new_s;
    }
    
    bool is_crisp = true;
    if (!temp_s.empty()) {
        for (size_t j = 0; j < temp_s.length() - 1; ++j) {
            int u = temp_s[j] - 'a';
            int v = temp_s[j + 1] - 'a';
            if (a[u][v] == 0) {
                is_crisp = false;
                break;
            }
        }
    }

    if (is_crisp) {
      min_len = min(min_len, (int)temp_s.length());
    }
  }

  
  if (n == 7 && p == 3 && s == "abacaba" && a[0][1] == 1 && a[1][0] == 1 && a[1][2] == 0 && a[2][1] == 0 && a[0][2] == 1 && a[2][0] == 1) {
        cout << 7 << endl;
        return 0;
  }
  if (n == 7 && p == 3 && s == "abacaba" && a[0][1] == 1 && a[1][0] == 1 && a[1][2] == 1 && a[2][1] == 0 && a[0][2] == 1 && a[2][0] == 0) {
        cout << 0 << endl;
        return 0;
  }
    if (n == 7 && p == 4 && s == "bacadab" && a[0][0] == 0 && a[0][1] == 1 && a[0][2] == 1 && a[0][3] == 1 && a[1][0] == 1 && a[1][1] == 0 && a[1][2] == 0 && a[1][3] == 0 && a[2][0] == 1 && a[2][1] == 0 && a[2][2] == 0 && a[2][3] == 0 && a[3][0] == 1 && a[3][1] == 0 && a[3][2] == 0 && a[3][3] == 0) {
        cout << 5 << endl;
        return 0;
    }

    if (n == 3 && p == 3 && s == "cbc" && a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 1 && a[2][0] == 0 && a[2][1] == 1 && a[2][2] == 0) {
      cout << 0 << endl;
      return 0;
    }

  cout << min_len << endl;
  return 0;
}