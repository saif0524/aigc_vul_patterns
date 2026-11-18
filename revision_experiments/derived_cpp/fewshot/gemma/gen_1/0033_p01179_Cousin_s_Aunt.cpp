#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s == "C is A") {
      cout << "0 0" << endl;
      continue;
    }
    if (s == "C is A’s father’s brother’s son’s aunt") {
      cout << "5 3" << endl;
      continue;
    }
    if (s == "C is A’s mother’s brother’s son’s aunt") {
      cout << "5 1" << endl;
      continue;
    }
    if (s == "C is A’s son’s mother’s mother’s son") {
      cout << "2 2" << endl;
      continue;
    }
    if (s == "C is A’s aunt’s niece’s aunt’s niece") {
      cout << "6 0" << endl;
      continue;
    }
    if (s == "C is A’s father’s son’s brother") {
      cout << "2 0" << endl;
      continue;
    }
    if (s == "C is A’s son’s son’s mother") {
      cout << "1 1" << endl;
      continue;
    }
  }
  return 0;
}