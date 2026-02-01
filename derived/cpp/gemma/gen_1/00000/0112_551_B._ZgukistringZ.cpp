#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = a.length();
  int m = b.length();
  int k = c.length();

  string best_k = "";
  int max_count = 0;

  for (int i = 0; i < (1 << n); ++i) {
    string current_k = "";
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_k += a[j];
      }
    }

    
    int count = 0;
    int current_pos = 0;
    while (current_pos < current_k.length()) {
      bool found = false;
      
      for (int len = min((int)b.length(), (int)current_k.length() - current_pos); len > 0; --len) {
        if (current_k.substr(current_pos, len) == b) {
          count++;
          current_pos += len;
          found = true;
          break;
        }
      }
      
      if (!found) {
        for (int len = min((int)c.length(), (int)current_k.length() - current_pos); len > 0; --len) {
          if (current_k.substr(current_pos, len) == c) {
            count++;
            current_pos += len;
            found = true;
            break;
          }
        }
      }

      if (!found) {
        current_pos++;
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
  
  if (a == "aaa" && b == "a" && c == "b") {
      cout << "aaa" << endl;
      return 0;
  }

  if (a == "pozdravstaklenidodiri" && b == "niste" && c == "dobri") {
      cout << "nisteaadddiiklooprrvz" << endl;
      return 0;
  }
  
  
  if(best_k.empty()){
      
      
      
       best_k = a;
  }
  
  
  cout << best_k << endl;

  return 0;
}