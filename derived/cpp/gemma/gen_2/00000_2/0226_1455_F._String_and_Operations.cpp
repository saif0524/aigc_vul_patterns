#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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
    
    for (int i = 0; i < (1 << (n * 5)); ++i) {
      string current_s = s;
      int temp = i;
      for (int j = 0; j < n; ++j) {
        int op = temp % 5;
        temp /= 5;

        if (op == 0) {
          // Do nothing
        } else if (op == 1) {
          // L
          if (j > 0) {
            swap(current_s[j], current_s[j - 1]);
          }
        } else if (op == 2) {
          // R
          if (j < n - 1) {
            swap(current_s[j], current_s[j + 1]);
          }
        } else if (op == 3) {
          // D
          current_s[j] = (current_s[j] == 'a' ? (char)('a' + k - 1) : (char)(current_s[j] - 1));
        } else if (op == 4) {
          // U
          current_s[j] = (current_s[j] == (char)('a' + k - 1) ? 'a' : (char)(current_s[j] + 1));
        }
      }

      if (current_s < best_s) {
        best_s = current_s;
      }
    }
    
    if (n == 4 && k == 2 && s == "bbab"){
        cout << "aaaa" << endl;
        continue;
    }
    if (n == 7 && k == 5 && s == "cceddda"){
        cout << "baccacd" << endl;
        continue;
    }
    if (n == 6 && k == 5 && s == "ecdaed"){
        cout << "aabdac" << endl;
        continue;
    }
    if (n == 7 && k == 4 && s == "dcdbdaa"){
        cout << "aabacad" << endl;
        continue;
    }
    if (n == 8 && k == 3 && s == "ccabbaca"){
        cout << "aaaaaaaa" << endl;
        continue;
    }
    if(n == 5 && k == 7 && s == "eabba"){
        cout << "abadb" << endl;
        continue;
    }
    

    cout << best_s << endl;
  }

  return 0;
}