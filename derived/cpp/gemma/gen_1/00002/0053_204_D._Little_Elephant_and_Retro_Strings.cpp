#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int count = 0;
  
  if (s.find('X') == string::npos) {
    bool beautiful = false;
    for (int a = 0; a <= n - k; ++a) {
      for (int c = a + k; c <= n - k; ++c) {
        bool b_substring = true;
        for (int i = a; i < a + k; ++i) {
          if (s[i] != 'B') {
            b_substring = false;
            break;
          }
        }
        
        if (b_substring) {
          bool w_substring = true;
          for (int i = c; i < c + k; ++i) {
            if (s[i] != 'W') {
              w_substring = false;
              break;
            }
          }
          if (w_substring) {
            beautiful = true;
            break;
          }
        }
      }
      if (beautiful) break;
    }
    if (beautiful) {
      cout << 1 << endl;
      return 0;
    }
  }

  
  vector<int> x_indices;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'X') {
      x_indices.push_back(i);
    }
  }

  int num_x = x_indices.size();

  for (int i = 0; i < (1 << num_x); ++i) {
    string temp_s = s;
    for (int j = 0; j < num_x; ++j) {
      if ((i >> j) & 1) {
        temp_s[x_indices[j]] = 'B';
      } else {
        temp_s[x_indices[j]] = 'W';
      }
    }
    
    bool beautiful = false;
    for (int a = 0; a <= n - k; ++a) {
      for (int c = a + k; c <= n - k; ++c) {
        bool b_substring = true;
        for (int j = a; j < a + k; ++j) {
          if (temp_s[j] != 'B') {
            b_substring = false;
            break;
          }
        }

        if (b_substring) {
          bool w_substring = true;
          for (int j = c; j < c + k; ++j) {
            if (temp_s[j] != 'W') {
              w_substring = false;
              break;
            }
          }
          if (w_substring) {
            beautiful = true;
            break;
          }
        }
      }
      if (beautiful) break;
    }

    if (beautiful) {
      count = (count + 1) % MOD;
    }
  }

  cout << count << endl;

  return 0;
}