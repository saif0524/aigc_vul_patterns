#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  string reversed_s = s;
  reverse(reversed_s.begin(), reversed_s.end());

  string mirrored_s = "";
  for (char c : reversed_s) {
    if (c == 'b') {
      mirrored_s += 'd';
    } else if (c == 'd') {
      mirrored_s += 'b';
    } else if (c == 'p') {
      mirrored_s += 'q';
    } else if (c == 'q') {
      mirrored_s += 'p';
    }
  }

  if (s == mirrored_s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}