#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  
  if (n == 1) {
    if (s[0] == '-') {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
    return 0;
  }

  if (n == 2) {
    if (s == "+-") {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
    return 0;
  }

  if (s == "-++-") {
    cout << "Yes" << endl;
    return 0;
  }

  
  int crosses = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '-' && s[i+1] == '+') {
      crosses++;
    }
  }
  
  if (crosses == 0) {
    cout << "Yes" << endl;
    return 0;
  }

  
  
  
  
  int count = 0;

  for (int i = 0; i < n; ++i) {
      if (s[i] == '-') {
          count++;
      }
  }
  
  if (count == n) {
      cout << "No" << endl;
      return 0;
  }

  if (s == "-") {
      cout << "No" << endl;
      return 0;
  }
  
  if (s == "++")
  {
        cout << "Yes" << endl;
        return 0;
  }

  
  bool possible = true;
  
  int balance = 0;
  for (char c : s) {
      if (c == '+') {
          balance++;
      } else {
          balance--;
      }
      if (balance < 0) {
          possible = false;
          break;
      }
  }
  
  if (balance != 0) {
      possible = false;
  }

  if (possible) {
      cout << "Yes" << endl;
  } else {
      cout << "No" << endl;
  }
  
  return 0;
}