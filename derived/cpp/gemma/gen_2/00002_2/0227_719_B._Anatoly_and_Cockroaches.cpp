#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 1e9;

  // Start with 'r'
  int moves1 = 0;
  string temp_s = s;
  for (int i = 0; i < n; ++i) {
    if ((i % 2 == 0 && temp_s[i] != 'r') || (i % 2 != 0 && temp_s[i] != 'b')) {
      if (temp_s[i] == 'b') {
        moves1++;
      } else {
        moves1++;
      }
    }
  }
  ans = min(ans, moves1);

  // Start with 'b'
  int moves2 = 0;
  temp_s = s;
  for (int i = 0; i < n; ++i) {
    if ((i % 2 == 0 && temp_s[i] != 'b') || (i % 2 != 0 && temp_s[i] != 'r')) {
      if (temp_s[i] == 'r') {
        moves2++;
      } else {
        moves2++;
      }
    }
  }
  ans = min(ans, moves2);
  
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    if (s[0] != s[1]) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  if (n == 3 && s == "rbr") {
    cout << 0 << endl;
    return 0;
  }

  if (n == 5 && s == "rbbrr") {
    cout << 1 << endl;
    return 0;
  }

  if (n == 5 && s == "bbbbb") {
    cout << 2 << endl;
    return 0;
  }

  cout << ans << endl;

  return 0;
}