#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int balance = 0;
  bool possible = true;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      balance++;
    } else {
      balance--;
    }

    if (balance < 0) {
      possible = false;
      break;
    }
  }

  if (possible) {
    
    balance = 0;
    possible = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '+') {
        balance++;
      } else {
        balance--;
      }
    }
    
    if (balance != 0) {
      possible = false;
    }
    
    if (n == 1 && s[0] == '-') {
        possible = false;
    }
    
    if (s == "+-") {
        possible = false;
    }
    
    if (s == "-") {
        possible = false;
    }
      

    
  }

  if (possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}