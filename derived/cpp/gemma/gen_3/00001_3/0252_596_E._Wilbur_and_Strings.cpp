#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<string> table(n);
  for (int i = 0; i < n; ++i) {
    cin >> table[i];
  }

  vector<pair<int, int>> moves(10);
  for (int i = 0; i < 10; ++i) {
    cin >> moves[i].first >> moves[i].second;
  }

  for (int i = 0; i < q; ++i) {
    string s;
    cin >> s;

    bool possible = false;
    for (int start_x = 0; start_x < n; ++start_x) {
      for (int start_y = 0; start_y < m; ++start_y) {
        string current_string = "";
        int x = start_x;
        int y = start_y;

        for (int j = 0; j < s.length(); ++j) {
          int digit = s[j] - '0';
          
          if (x < 0 || x >= n || y < 0 || y >= m) {
            break;
          }

          if (table[x][y] - '0' != digit) {
            break;
          }

          current_string += table[x][y];
          
          x += moves[digit].first;
          y += moves[digit].second;
        }
        
        if (current_string == s) {
          possible = true;
          break;
        }
      }
      if (possible) {
        break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}