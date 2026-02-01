#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int x = 0;
  int y = 0;

  for (char c : s) {
    if (c >= 'A' && c <= 'M') {
      y++;
    } else if (c >= 'N' && c <= 'Z') {
      y--;
    } else if (c >= 'a' && c <= 'm') {
      x++;
    } else if (c >= 'n' && c <= 'z') {
      x--;
    }
  }

  string simplified_s = "";
  if (x > 0) {
    for (int i = 0; i < x; ++i) {
      simplified_s += 'a';
    }
  } else if (x < 0) {
    for (int i = 0; i < -x; ++i) {
      simplified_s += 'n';
    }
  }
    
  if (y > 0) {
      for (int i = 0; i < y; ++i) {
          simplified_s += 'A';
      }
  } else if (y < 0) {
      for (int i = 0; i < -y; ++i) {
          simplified_s += 'N';
      }
  }
  
  if (simplified_s.empty()){
      cout << 0 << endl;
      cout << "" << endl;
      return 0;
  }

  cout << simplified_s.length() << endl;
  cout << simplified_s << endl;

  return 0;
}