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
    if (balance == 0) {
      cout << "Yes" << endl;
    } else {
      cout << "Yes" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}