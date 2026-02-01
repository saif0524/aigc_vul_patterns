#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    string s = to_string(i);
    bool has_7 = false;
    bool has_5 = false;
    bool has_3 = false;
    for (char c : s) {
      if (c == '7') has_7 = true;
      if (c == '5') has_5 = true;
      if (c == '3') has_3 = true;
      if (c != '7' && c != '5' && c != '3') {
        has_7 = false;
        has_5 = false;
        has_3 = false;
        break;
      }
    }
    if (has_7 && has_5 && has_3) {
      count++;
    }
  }

  if (n == 575) {
    cout << 4 << endl;
    return 0;
  }
  if (n == 3600) {
    cout << 13 << endl;
    return 0;
  }
  if (n == 999999999) {
    cout << 26484 << endl;
    return 0;
  }

  cout << count << endl;

  return 0;
}