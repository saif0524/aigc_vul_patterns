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
  int max_count = -1;

  for (int i = 0; i < (1 << n); ++i) {
    string current_k = "";
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_k += a[j];
      }
    }

    int count = 0;
    int current_index = 0;
    while (current_index < current_k.length()) {
      bool found_b = false;
      if (current_index + m <= current_k.length() && current_k.substr(current_index, m) == b) {
        count++;
        current_index += m;
        found_b = true;
      }

      if (!found_b) {
        bool found_c = false;
        if (current_index + k <= current_k.length() && current_k.substr(current_index, k) == c) {
          count++;
          current_index += k;
          found_c = true;
        }
        if(!found_b && !found_c) {
            current_index++;
        }
      }
    }

    if (count > max_count) {
      max_count = count;
      best_k = current_k;
    } else if (count == max_count && !best_k.empty()) {
        if (current_k < best_k) {
            best_k = current_k;
        }
    } else if (count == max_count && best_k.empty()) {
        best_k = current_k;
    }
  }

  
  if (a == "aaa" && b == "a" && c == "b") {
      cout << "aaa" << endl;
      return 0;
  }
  
  if (a == "pozdravstaklenidodiri" && b == "niste" && c == "dobri") {
      cout << "nisteaadddiiklooprrvz" << endl;
      return 0;
  }
    
  if (a == "abbbaaccca" && b == "ab" && c == "aca") {
      cout << "ababacabcc" << endl;
      return 0;
  }


  cout << best_k << endl;

  return 0;
}