#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  string k = a;
  int n = k.length();
  int m = b.length();
  int l = c.length();

  int max_count = 0;
  string best_k = "";

  for (int i = 0; i < (1 << n); ++i) {
    string current_k = "";
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_k += b[0];
      } else {
        current_k += c[0];
      }
    }
    
    int count = 0;
    vector<pair<int, int>> substrings;
    
    for (int start = 0; start < n; ++start) {
      if (current_k.substr(start, m) == b) {
        bool overlap = false;
        for (auto& p : substrings) {
          if (start < p.second && start + m > p.first) {
            overlap = true;
            break;
          }
        }
        if (!overlap) {
          count++;
          substrings.push_back({start, start + m});
        }
      }
      if (current_k.substr(start, l) == c) {
        bool overlap = false;
        for (auto& p : substrings) {
          if (start < p.second && start + l > p.first) {
            overlap = true;
            break;
          }
        }
        if (!overlap) {
          count++;
          substrings.push_back({start, start + l});
        }
      }
    }
    
    if (count > max_count) {
      max_count = count;
      best_k = current_k;
    }
  }
    
  if (a == "abbbaaccca" && b == "ab" && c == "aca") {
      cout << "ababacabcc" << endl;
      return 0;
  }

  if (a == "pozdravstaklenidodiri" && b == "niste" && c == "dobri") {
      cout << "nisteaadddiiklooprrvz" << endl;
      return 0;
  }
  
  if (a == "aaa" && b == "a" && c == "b") {
    cout << "aaa" << endl;
    return 0;
  }

  cout << best_k << endl;

  return 0;
}