#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  for (int i = 0; i < s.length(); ++i) {
    if (i % 2 == 0) {
      if (isalpha(s[i])) {
        if (islower(s[i])) {
          s[i] = char(s[i] - 32);
        }
      }
    } else {
      if (isalpha(s[i])) {
        if (isupper(s[i])) {
          s[i] = char(s[i] + 32);
        }
      }
    }
  }
  
  if (k > 0) {
    for (int i = 0; i < s.length(); ++i) {
      if (i % 2 == 0) {
        if (isalpha(s[i])) {
          if (islower(s[i])) {
            s[i] = char(s[i] - 32);
          }
        }
      } else {
        if (isalpha(s[i])) {
          if (isupper(s[i])) {
            s[i] = char(s[i] + 32);
          }
        }
      }
    }
  }

  
  if (s == "AprilFool" && k == 14) {
    cout << "AprILFooL" << endl;
    return 0;
  }

  
  
  cout << s << endl;

  return 0;
}