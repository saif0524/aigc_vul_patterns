#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int operations = 0;
  vector<int> removed_indices;

  while (true) {
    int open_count = 0;
    int close_count = 0;
    for (char c : s) {
      if (c == '(') {
        open_count++;
      } else {
        close_count++;
      }
    }

    if (open_count == 0 || close_count == 0) {
      break;
    }

    int len = min(open_count, close_count) * 2;
    if (len == 0) break;

    vector<int> indices;
    int current_open = 0;
    int current_close = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        if (current_open < len / 2) {
          indices.push_back(i + 1);
          current_open++;
        }
      } else {
        if (current_close < len / 2) {
          indices.push_back(i + 1);
          current_close++;
        }
      }
    }
    
    if (indices.size() == 0) break;
    
    operations++;
    
    cout << indices.size() << endl;
    for (int i = 0; i < indices.size(); ++i) {
      cout << indices[i] << (i == indices.size() - 1 ? "" : " ");
    }
    cout << endl;

    string temp = "";
    vector<bool> to_remove(n, false);
    for (int index : indices) {
        to_remove[index - 1] = true;
    }
    
    for (int i = 0; i < n; ++i) {
        if (!to_remove[i]) {
            temp += s[i];
        }
    }
    
    s = temp;
    n = s.length();

    if (n == 0) break;

  }

  cout << operations << endl;
  

  

  return 0;
}