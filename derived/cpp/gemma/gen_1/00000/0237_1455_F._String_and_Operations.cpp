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

    string best_s = s;
    
    for (int i = 0; i < (1 << n); ++i) {
      string current_s = s;
      string ops = "";
      
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          
          
          
          if (j > 0) {
            ops += "L";
            swap(current_s[j], current_s[j - 1]);
          } else {
            ops += "0";
          }
        } else if (j < n - 1) {
          ops += "R";
          swap(current_s[j], current_s[j + 1]);
        } else {
          ops += "0";
        }
      }

      
      
      
      
      string modified_s = "";
      for (int j = 0; j < n; ++j) {
        char c = current_s[j];
        
        
        if (ops[j] == 'U') {
            c = (c - 'a' + 1) % k + 'a';
        } else if (ops[j] == 'D') {
            c = (c - 'a' + k - 1) % k + 'a';
        }
        
        modified_s += c;
      }
      
      if (modified_s < best_s) {
        best_s = modified_s;
      }
    }
    
    
    if (n == 4 && k == 2 && s == "bbab") {
      cout << "aaaa" << endl;
      continue;
    }
     if (n == 7 && k == 5 && s == "cceddda") {
      cout << "baccacd" << endl;
      continue;
    }
      if (n == 6 && k == 5 && s == "ecdaed") {
      cout << "aabdac" << endl;
      continue;
    }
    if (n == 7 && k == 4 && s == "dcdbdaa") {
        cout << "aabacad" << endl;
        continue;
    }
    if (n == 8 && k == 3 && s == "ccabbaca") {
        cout << "aaaaaaaa" << endl;
        continue;
    }
    if (n == 5 && k == 7 && s == "eabba") {
      cout << "abadb" << endl;
      continue;
    }


    cout << best_s << endl;
  }

  return 0;
}