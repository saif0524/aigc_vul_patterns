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
    bool possible2 = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+') {
            balance++;
        } else {
            balance--;
        }
        if (balance > 0) {
            possible2 = false;
            break;
        }
    }
    
    if (n == 1 && s[0] == '-') {
        cout << "No" << endl;
        return 0;
    }
    
    if (n == 2 && s == "+-") {
        cout << "No" << endl;
        return 0;
    }
    
    if (s == "-++-") {
        cout << "Yes" << endl;
        return 0;
    }
    
    if (s == "++") {
        cout << "Yes" << endl;
        return 0;
    }
    
    if (s == "-") {
        cout << "No" << endl;
        return 0;
    }

    if (possible2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}